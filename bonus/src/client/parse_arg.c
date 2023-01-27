/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:44:41 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/23 08:43:43 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_check_arg(char *arg)
{
	if (!arg || !*arg)
	{
		write(2, "Error: Invalid PID provided!\n", 29);
		return (0);
	}
	while (*arg)
	{
		if (!ft_isdigit(*arg))
		{
			write(2, "Error: Invalid PID provided!\n", 29);
			return (0);
		}
		arg++;
	}
	return (1);
}
