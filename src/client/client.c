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

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac == 3)
	{
		if (ft_check_arg(av[1]))
		{
			server_pid = atoi(av[1]);
			if (kill(server_pid, 0) == -1)
			{
				ft_printf("Process is not running or does't exist.\n");
				return (1);
			}
			else
				ft_send_message(server_pid, av[2]);
		}
	}
	else
	{
		ft_printf("Usage: %s <server_pid> <string>\n", av[0]);
		return (1);
	}
	return (0);
}
