# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:25:14 by aigounad          #+#    #+#              #
#    Updated: 2023/01/27 04:42:34 by aigounad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC  = ft_bzero.c \
		ft_strlen.c \
		ft_memset.c \
		ft_isdigit.c

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
