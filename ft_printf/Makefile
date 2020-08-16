# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 11:07:45 by yel-alou          #+#    #+#              #
#    Updated: 2020/04/27 13:56:49 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
WALL = -Wall -Werror -Wextra
SRC = flag.c print_c.c print_p.c print_s.c print_x.c utils2.c ft_printf.c print_x_maj.c print_d.c print_pourcent.c print_u.c utils.c utils3.c utils4.c utils5.c
OBJ = $(SRC:.c=.o)
INCLUDE = ./

all : $(NAME)

%.o: %.c
	$(CC) -I $(INCLUDE) -c $(WALL) $< -o $@

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) $(OBJ)

re : fclean all

bonus:	all
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) -I $(INCLUDE) -c $(WALL) $< -o $@

.PHONY: all clean fclean re .c.o bonus
