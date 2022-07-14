/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:39:25 by cmartin-          #+#    #+#             */
/*   Updated: 2022/06/10 13:39:43 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./Printf/ft_printf.h"

typedef struct s_mov
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	tot;
}	t_mov;

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_mov	mov;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*head;
	size_t	size;
}	t_stack;

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_stack *stack);
int		ft_verif(t_stack *stack);

int		ft_atoi(const char *str);

char	**ft_split(char const *str, char const c);

//error
int	ft_dup(t_stack *stack, char *str);

//operations
void	ft_push(t_list *new, t_stack *stack);
t_list	*ft_pop(t_stack *stack);
void	ft_s(t_stack *stack, char c);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_p(t_stack *stack1, t_stack *stack2, char c);

void	ft_r(t_stack *stack, char c);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_reverse(t_stack *stack, char c);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

//pos
int		ft_pos(t_stack *stack, t_list *elem);
void	ft_put_pos(t_stack *stack);

//mov
int		ft_min(t_stack *stack);
void	ft_init_mov(t_mov *elem);
void	ft_mov_b(t_stack *stack, t_list *elem, size_t pos);
void	ft_mov_a(t_stack *stack, t_list *elem);
void	ft_mov_rr(t_list *elem);

void	ft_mov_rrr(t_list *elem);
void	ft_mov_add(t_stack *stackb, t_stack *stacka, t_list *elem, int cpt);
void	ft_put_mov(t_stack *stackb, t_stack *stacka);

//insert_sort
t_list	*ft_pick(t_stack *stack);
void	ft_insert(t_stack *stacka, t_stack *stackb, t_list *elem);
void	ft_rotate(t_stack *stack);

//sort
void	ft_sort(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_sort_few(t_stack	*stack);
void	ft_sort_many(t_stack *stack);

//recup
void	ft_strclear(char **str);
void	ft_recup(char **str, t_stack *stack);

#endif
