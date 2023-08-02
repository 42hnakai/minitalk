CC = cc
GFLAGS = -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT = client.c
SRC_SERVER = server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFTPRINTF):
	make -C ft_printf

$(NAME_CLIENT): $(LIBFTPRINTF) $(OBJ_CLIENT)
	$(CC) $(GFLAGS) $(OBJ_CLIENT) -L ft_printf -lftprintf -o $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFTPRINTF) $(OBJ_SERVER)
	$(CC) $(GFLAGS) $(OBJ_SERVER) -L ft_printf -lftprintf -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS): $(LIBFTPRINTF) $(OBJ_CLIENT_BONUS)
	$(CC) $(GFLAGS) $(OBJ_CLIENT_BONUS) -L ft_printf -lftprintf -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(LIBFTPRINTF) $(OBJ_SERVER_BONUS)
	$(CC) $(GFLAGS) $(OBJ_SERVER_BONUS) -L ft_printf -lftprintf -o $(NAME_SERVER_BONUS)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

.c.o:
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	make clean -C ft_printf
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)

fclean: clean
	make fclean -C ft_printf
	rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: clean fclean all re bonus
