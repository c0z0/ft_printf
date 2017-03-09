# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cserdean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/24 18:41:12 by cserdean          #+#    #+#              #
#    Updated: 2017/03/01 19:27:40 by cserdean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRC = ./src/*.c ./libft/*.c
LIBFT = ./libft/libft.a

HEADER = ./includes/

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(HEADER) $(SRC) 
	ar rc $(NAME) *.o
	ranlib $(NAME)
clean:
	make -C "./libft" clean
	/bin/rm -f *.o
fclean: clean
	make -C "./libft" fclean
	/bin/rm -f $(NAME)

re: fclean all
