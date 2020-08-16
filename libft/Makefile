# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 09:38:33 by yel-alou          #+#    #+#              #
#    Updated: 2019/11/19 12:49:27 by yel-alou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
WALL = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_bzero.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_calloc.c ft_isprint.c ft_memccpy.c ft_memset.c ft_split.c ft_strlcpy.c ft_strrchr.c ft_isalnum.c ft_itoa.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_strtrim.c ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_substr.c ft_strmapi.c
LST = ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c
OBJ = $(SRC:.c=.o)
LSTOBJ = $(LST:.c=.o)
INCLUDE = ./

all : $(NAME)

%.o: %.c
	$(CC) -I $(INCLUDE) -c $(WALL) $< -o $@

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ) $(LSTOBJ)

fclean : clean
	rm -f $(NAME) $(LSTOBJ)

re : fclean all

bonus:	all $(LSTOBJ)
	ar -rc $(NAME) $(OBJ) $(LSTOBJ)

%.o: %.c
	$(CC) -I $(INCLUDE) -c $(WALL) $< -o $@
