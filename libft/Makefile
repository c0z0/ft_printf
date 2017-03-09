# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cserdean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 13:09:37 by cserdean          #+#    #+#              #
#    Updated: 2017/02/10 12:49:37 by cserdean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

HEADER = ./includes/

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
