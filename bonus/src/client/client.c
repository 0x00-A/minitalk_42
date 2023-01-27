/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:48:33 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/14 22:48:33 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	catch_sig(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message recieved\n");
	exit(0);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	signal(SIGUSR1, catch_sig);
	if (ac == 3)
	{
		if (ft_check_arg(av[1]))
		{
			server_pid = atoi(av[1]);
			if (kill(server_pid, 0) == -1)
				ft_printf("Process with PID %d is not running.\n", server_pid);
			else
				ft_send_message(server_pid, av[2]);
		}
	}
	else
	{
		ft_printf("Usage: %s <server_pid> <string>\n", av[0]);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
