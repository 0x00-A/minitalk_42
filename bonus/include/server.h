/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 05:47:18 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/27 05:48:09 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

//includes
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include "../src/ft_printf/ft_printf.h"
# include "../src/libft/libft.h"

typedef struct s_params{
	pid_t			client_pid;
	unsigned char	character;
	int				byte;
	unsigned char	tab[4];
	int				index;
	int				nbyte;
}	t_params;

#endif