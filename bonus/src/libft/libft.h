/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 01:51:57 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/27 04:42:41 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

size_t	ft_strlen(const char *s);
void	ft_bzero(void	*s, size_t n);
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);

#endif