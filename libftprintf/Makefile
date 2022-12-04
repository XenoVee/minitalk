# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/13 17:19:52 by rmaes         #+#    #+#                  #
#    Updated: 2022/11/14 15:00:44 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

OBJECTS_DIR = objects/
SOURCES_DIR = sources/
PRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/

FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_min.c ft_max.c ft_btw.c ft_is_atoi.c ft_abs.c ft_ultoa.c ft_atoul.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_realloc.c \
		ft_digitcount.c ft_digitcount_unsigned.c ft_is_negative.c ft_strcmp.c \
		ft_null_array.c ft_sign.c
PRINTF_FILES = ft_printf_utils.c ft_printf.c writes.c writes_2.c
GNL_FILES = get_next_line.c get_next_line_utils.c \


SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))
PRINTF_SOURCES = $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
GNL_SOURCES = $(addprefix $(GNL_DIR), $(GNL_FILES))

OBJECTS = $(addprefix $(OBJECTS_DIR), $(FILES:.c=.o))
PRINTF_OBJECTS = $(PRINTF_SOURCES:.c=.o)
GNL_OBJECTS = $(GNL_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(PRINTF_OBJECTS) $(GNL_OBJECTS)
	@echo archving $@
	ar -rcsu $@ $^

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@$(CC) -c $(CFLAGS) -o $@ $^

$(PRINTF_DIR)%.o: $(PRINTF_DIR)%.c
	@$(CC) -c $(CFLAGS) -o $@ $^

$(GNL_DIR)%.o: $(GNL_DIR)%.c
	@$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@rm -f $(OBJECTS) $(GNL_OBJECTS) $(PRINTF_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
