
NAME = libftprintf.a

HEDEAR = ft_printf.h

CC = gcc -Wall -Wextra -Werror

SRC =	ft_printf.c \
		ft_tools_printf.c

SRC_O = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(HEDEAR) $(SRC_O)
	ar -rcs $(NAME) $(SRC_O)

%.o :	%.c
	$(CC) -o $@ -c $<

clean :
	rm -rf $(SRC_O)

fclean : clean
	rm -rf $(NAME)

re : fclean all