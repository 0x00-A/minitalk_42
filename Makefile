CC = cc
CFLAGS = -Iinclude -Wall -Wextra -Werror
NAME = $(NAME_CLIENT) $(NAME_SERVER)
NAME_CLIENT = client
NAME_SERVER = server
FT_PRINTF_BINARY = src/ft_printf/libftprintf.a
FT_PRINTF_DIR = src/ft_printf
FT_PRINTF = ftprintf
BONUS_PATH = ./bonus
MAKE_FLAG = --no-print-directory


SRC_CLIENT = src/client/client.c src/client/parse_arg.c src/client/send_message.c
SRC_SERVER = src/server/server.c

OBJ_CLIENT = $(SRC_CLIENT:c=o)
OBJ_SERVER = $(SRC_SERVER:c=o)

%.o : %.c
	$(CC) $(CFLAGS) -I../../include -c $< -o $@

all : $(NAME)

$(NAME) : $(FT_PRINTF_BINARY) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(CC) $(OBJ_CLIENT) $(FT_PRINTF_BINARY) -o $(NAME_CLIENT)
	$(CC) $(OBJ_SERVER) $(FT_PRINTF_BINARY) -o $(NAME_SERVER)

$(FT_PRINTF_BINARY) : FORCE
	@make $(MAKE_FLAG) -C $(FT_PRINTF_DIR)

FORCE :

bonus : FORCE
	@make $(MAKE_FLAG) -C $(BONUS_PATH)

clean :
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@make $(MAKE_FLAG) clean -C $(FT_PRINTF_DIR)
	@make $(MAKE_FLAG) clean -C $(BONUS_PATH)

fclean : clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make $(MAKE_FLAG) fclean -C $(FT_PRINTF_DIR)
	@make $(MAKE_FLAG) fclean -C $(BONUS_PATH)
