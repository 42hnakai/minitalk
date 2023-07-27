CC = cc
GFLAGS = -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT = client.c ft_atoi.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):$(OBJ_CLIENT)
	$(CC) $(GFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER):$(OBJ_SERVER)
	$(CC) $(GFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

.c.o:
	$(CC) $(GFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: clean fclean all re

