/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:43:54 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/27 06:16:30 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_send_char(pid_t server_pid, char c)
{
	int	byte;

	byte = 8;
	while (byte--)
	{
		if (c & (1 << byte))
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_printf("Process has stoped running!\n");
				return (1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_printf("Process has stoped running!\n");
				return (1);
			}
		}
		usleep(500);
	}
	return (0);
}

void	ft_send_message(pid_t server_pid, char *string)
{
	int	len;
	int	i;

	len = ft_strlen(string);
	i = 0;
	while (i <= len)
	{
		if (ft_send_char(server_pid, string[i]) == 1)
			break ;
		i++;
	}
}
