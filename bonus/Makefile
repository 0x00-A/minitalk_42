CC = cc
CFLAGS = -Iinclude -Wall -Wextra -Werror
NAME = $(NAME_CLIENT) $(NAME_SERVER)
NAME_CLIENT = client
NAME_SERVER = server
FT_PRINTF_BINARY = src/ft_printf/libftprintf.a
FT_PRINTF_DIR = src/ft_printf
FT_PRINTF = ftprintf
LIBFT_BINARY = ./src/libft/libft.a
LIBFT_DIR = ./src/libft
LIBFT_NAME = ft

SRC_CLIENT = src/client/client.c src/client/parse_arg.c src/client/send_message.c
SRC_SERVER = src/server/server.c

OBJ_CLIENT = $(SRC_CLIENT:c=o)
OBJ_SERVER = $(SRC_SERVER:c=o)

%.o : %.c
	$(CC) $(CFLAGS) -I../../include -c $< -o $@

all : $(NAME)

$(NAME) : $(FT_PRINTF_BINARY) $(LIBFT_BINARY) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(CC) $(OBJ_CLIENT) -L$(LIBFT_DIR) -l$(LIBFT_NAME) $(FT_PRINTF_BINARY) -o $(NAME_CLIENT)
	$(CC) $(OBJ_SERVER) -L$(LIBFT_DIR) -l$(LIBFT_NAME) $(FT_PRINTF_BINARY) -o $(NAME_SERVER)

$(FT_PRINTF_BINARY) : FORCE
	@make -C $(FT_PRINTF_DIR)

$(LIBFT_BINARY) : FORCE
	@make -C $(LIBFT_DIR)

FORCE :

clean :
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@make clean -C $(FT_PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make fclean -C $(FT_PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
