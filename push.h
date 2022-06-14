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
# include <unistd.h>
# include "./Printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				pos;
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
int		ft_atoi(const char *str);
char	**ft_split(char const *str, char const c);

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
int		ft_pos(t_stack *stack, t_list *elem);

void	ft_put_pos(t_stack *stack);
int		ft_verif(t_stack *stack);

//sort
void	ft_sort_three(t_stack *stack);
#endif
