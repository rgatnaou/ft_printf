# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 15:03:00 by rgatnaou          #+#    #+#              #
#    Updated: 2021/12/09 15:03:03 by rgatnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

CC = gcc -Wall -Wextra -Werror

SRC =	ft_printf.c \
		ft_tools_printf.c  \
		ft_tools_printf0.c

SRC_O = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(HEADER) $(SRC_O)
	ar -rcs $(NAME) $(SRC_O) $(HEADER)

%.o :	%.c $(HEADER)
	$(CC) -o $@ -c $<

clean :
	rm -rf $(SRC_O)

fclean : clean
	rm -rf $(NAME)

re : fclean all