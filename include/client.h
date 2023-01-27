/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:42:12 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/27 05:42:33 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

//includes
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include "../src/ft_printf/ft_printf.h"

int		ft_check_arg(char *arg);
void	ft_send_message(pid_t server_pid, char *string);

#endif