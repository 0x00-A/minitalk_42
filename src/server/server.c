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

void	ft_sig_handler(int sig_num, siginfo_t *info, void *context)
{
	static pid_t			client_pid = 0;
	static unsigned char	character = 0;
	static int				byte = 7;

	(void)context;
	if (client_pid != info->si_pid)
	{
			client_pid = info->si_pid;
			character = 0;
			byte = 7;
	}
	if (sig_num == SIGUSR1)
	{
		character = character | (1 << byte);
		byte--;
	}
	else
		byte--;
	if (byte == -1)
	{
		if (character < 128)
			write(1, &character, 1);
		character = 0;
		byte = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID = %d\n", getpid());
	while (1)
		pause();
}
