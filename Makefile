CC = cc
GFLAGS = -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER = server
NAME_SERVER_BONUS = server_bonus
SRC_CLIENT = client.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER = server.c
SRC_SERVER_BONUS = server_bonus.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):$(OBJ_CLIENT)
	make -C ft_printf
	$(CC) $(GFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER):$(OBJ_SERVER)
	$(CC) $(GFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS):$(OBJ_CLIENT_BONUS)
	make -C ft_printf
	$(CC) $(GFLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS)

$(NAME_CLIENT_BONUS):$(OBJ_SERVER_BONUS)
	$(CC) $(GFLAGS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER_BONUS)

bonus: $(NAME_CLIENT_BONUS) $(NAME_CLIENT_BONUS)

.c.o:
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	make clean -C ft_printf
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	make fclean -C ft_printf
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: clean fclean all re bonus
