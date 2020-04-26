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
SOURCE = ft_case.c ft_casetoa.c ft_check.c ft_percent.c ft_printf.c ft_result_apply.c ft_result.c ft_set.c ft_star_apply.c
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
