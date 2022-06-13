SRCS = 

OBJS = $(SRCS:%.c=%.o)

CC   = gcc -Wall -Wextra -Werror

NAME = push_swap

HEAD = push.h

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

$(NAME): $(OBJS) $(HEAD)
	$(CC) -c $< -Iincludes -o $@

.PHONY: all clean fclean re
