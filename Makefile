# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 00:34:17 by tlee              #+#    #+#              #
#    Updated: 2020/04/23 00:34:41 by tlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SOURCE = *.c
OBJECT = *.o
INCLUDE = .

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SOURCE) -I $(INCLUDE)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@rm -f ./libft/*.o

fclean: clean
	@rm -f $(NAME) ./libft/libft.a

re: fclean all

.PONY: all clean fclean re
