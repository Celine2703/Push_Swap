SRCS = flag_s.c flag_i.c ft_putchar_fd.c ft_putnbr_base.c ft_putstr_fd.c ft_strlen.c printf.c

OBJS = $(SRCS:%.c=%.o)

CC   = gcc -Wall -Wextra -Werror

NAME = libftprintf.a

HEAD = ft_printf.h

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

$(NAME): $(OBJS)
	ar -rcs libftprintf.a $(OBJS)

%.o: %.c $(HEAD)
	$(CC) -c $< -Iincludes -o $@

.PHONY: all clean fclean re
