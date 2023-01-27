/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:59:16 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/16 01:59:16 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_check_id(t_params *params, siginfo_t *info)
{
	if (params->client_pid == 0)
		params->client_pid = info->si_pid;
	else if (params->client_pid != info->si_pid)
	{
		params->client_pid = info->si_pid;
		params->character = 0;
		params->byte = 7;
		ft_bzero(params->tab, 4);
		params->index = 0;
	}
}

void	ft_catch_character(t_params *params, int sig_num)
{
	if (sig_num == SIGUSR1)
	{
		params->character = params->character | (1 << params->byte);
		params->byte--;
	}
	else
		params->byte--;
}

void	ft_print_unicode(t_params *params)
{
	int	j;

	j = 0;
	params->tab[params->index++] = params->character;
	if (params->character >= 192 && params->character < 224)
		params->nbyte = 2;
	else if (params->character >= 224 && params->character < 240)
		params->nbyte = 3;
	else if (params->character >= 240)
		params->nbyte = 4;
	if (params->index == params->nbyte)
	{
		while (j < params->index)
			write(1, &params->tab[j++], 1);
		ft_bzero(params->tab, 4);
		params->index = 0;
	}
}

void	ft_sig_handler(int sig_num, siginfo_t *info, void *context)
{
	static t_params	params = {0, 0, 7, "0000", 0, 0};

	(void)context;
	ft_check_id(&params, info);
	ft_catch_character(&params, sig_num);
	if (params.byte == -1)
	{
		if (params.character == 0)
			kill(info->si_pid, SIGUSR1);
		else if (params.character <= 127)
			write(1, &params.character, 1);
		else
			ft_print_unicode(&params);
		params.character = 0;
		params.byte = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", getpid());
	sa.sa_sigaction = ft_sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
