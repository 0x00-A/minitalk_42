/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:48:28 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/27 05:48:53 by aigounad         ###   ########.fr       */
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
# include "../src/libft/libft.h"

int		ft_check_arg(char *arg);
void	ft_send_message(pid_t server_pid, char *string);

#endif