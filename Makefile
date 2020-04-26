# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 00:34:17 by tlee              #+#    #+#              #
#    Updated: 2020/04/27 01:04:23 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SOURCE = *.c libft/*.c
OBJECT = *.o
INCLUDE = .

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SOURCE) -I $(INCLUDE)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PONY: all clean fclean re
