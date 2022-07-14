SRCS = ft_atoi.c ft_sort.c ft_split.c ft_utiles.c operations.c operations_bis.c mov.c mov_bis.c recup.c pos.c insert_sort.c error.c

SRCSBONUS = ./BONUS/ft_atoi_bonus.c ./BONUS/ft_split_bonus.c ./BONUS/ft_utiles_bonus.c ./BONUS/operations_bonus.c ./BONUS/operations_bis_bonus.c ./BONUS/ft_sort_bonus.c ./BONUS/get_next_line_bonus.c ./BONUS/get_next_line_utils_bonus.c

OBJS = $(SRCS:%.c=%.o)

OBJSBONUS = $(SRCSBONUS:%.c=%.o)

CC   = gcc -g3 -Wall -Wextra -Werror

NAME = push_swap

NAMEBONUS = checker

HEAD = push.h

HEADBONUS = ./BONUS/push_bonus.h

all: $(NAME)

bonus:	$(NAMEBONUS)

clean:
	make -C ./Printf clean
	rm -f $(OBJS)
	rm -f $(OBJSBONUS)

fclean: clean
	make -C ./Printf fclean
	rm -f $(NAME)
	rm -f $(NAMEBONUS)

re: fclean
	make all

$(NAME): $(OBJS) $(HEAD)
	make -C ./Printf
	$(CC) $(SRCS) -Iincludes ./Printf/libftprintf.a -o $@

$(NAMEBONUS):	$(OBJSBONUS) $(HEADBONUS)
	$(CC) $(SRCSBONUS) -Iincludes -o $@

.PHONY: all bonus clean fclean re
