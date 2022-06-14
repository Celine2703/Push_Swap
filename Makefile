SRCS = ft_atoi.c ft_sort.c ft_split.c ft_utiles.c operations.c operations_bis.c operations_ter.c recup.c

OBJS = $(SRCS:%.c=%.o)

CC   = gcc -Wall -Wextra -Werror

NAME = push_swap

HEAD = push.h

all: $(NAME)

clean:
	make -C ./Printf clean
	rm -f $(OBJS)

fclean: clean
	make -C ./Printf fclean
	rm -f $(NAME)

re: fclean
	make all

$(NAME): $(OBJS) $(HEAD)
	make -C ./Printf
	$(CC) $(SRCS) -Iincludes ./Printf/libftprintf.a -o $@

.PHONY: all clean fclean re
