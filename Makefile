# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 20:33:37 by hmochida          #+#    #+#              #
#    Updated: 2021/08/18 23:19:16 by hmochida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=burrito.c ft_printf.c ft_uitoa.c pstr.c ft_uitoa16.c \
ft_itoa.c ft_strlen.c pchar.c ft_strdup.c

CDBGFLAGS=-g -fsanitize=address

OBJ=$(SRC:.c=.o)

$(NAME): ft_printf.h
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
