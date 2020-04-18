NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SOURCE = result_flag.c percent.c result.c set.c get.c ft_printf.c caseToa.c case.c libft/*.c
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
