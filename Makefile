# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 20:33:37 by hmochida          #+#    #+#              #
#    Updated: 2021/08/18 03:11:35 by hmochida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=clang

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

SRC=burrito.c ft_printf.c ft_uitoa.c pstr.c ft_uitoa16.c \
ft_itoa.c ft_strlen.c pchar.c ft_strdup.c

DBG=dbg.a

DCC=clang

CDBGFLAGS=-g -fsanitize=address

OBJ=$(SRC:.c=.o)

$(NAME): ft_printf.h
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(DBG): ft_printf.h
	$(DCC) $(CDBGFLAGS) -c $(SRC)
	ar rc $(DBG) $(OBJ)
	ranlib $(DBG)

all: $(NAME)

d: $(DBG)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(DBG)

re: fclean all

.PHONY: clean fclean
