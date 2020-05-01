# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 00:34:17 by tlee              #+#    #+#              #
#    Updated: 2020/05/01 23:00:47 by tlee             ###   ########.fr        #
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
	@rm -f libft/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/*.a

re: fclean all

.PONY: all clean fclean re
