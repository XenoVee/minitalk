# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/01 13:10:16 by rmaes         #+#    #+#                  #
#    Updated: 2022/12/03 20:27:31 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCES = client.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = client.h
LIBFT = ../libftprintf/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = client
TEST = test

all: $(NAME)

$(TEST): $(NAME)
	$(CC) -g -o $@ $^
	make clean

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
