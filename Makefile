# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/01 13:10:16 by rmaes         #+#    #+#                  #
#    Updated: 2022/12/04 19:50:14 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCES_SERVER = server_dir/server.c
OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)

SOURCES_CLIENT = client_dir/client.c
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)

LIBFT = libftprintf/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME_SERVER = server
NAME_CLIENT = client
TEST = test

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C libftprintf

$(NAME_SERVER): $(OBJECTS_SERVER) $(LIBFT)
	$(CC) $^ -o $@

$(NAME_CLIENT): $(OBJECTS_CLIENT) $(LIBFT)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS_SERVER) $(OBJECTS_CLIENT) 
	make clean -C libftprintf

fclean: clean
	make fclean -C libftprintf
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
