/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:48:18 by cmartin-          #+#    #+#             */
/*   Updated: 2022/06/13 13:48:19 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_r(t_stack *stack, char c)
{
	t_list	*list;

	if (stack ->size <= 1)
		return ;
	list = stack ->head;
	while (list ->next)
		list = list ->next;
	list ->next = ft_pop(stack);
	stack ->size ++;
	list ->next ->next = NULL;
	if (c)
		ft_printf("r%c\n", c);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_r(stack_a, 0);
	ft_r(stack_b, 0);
	ft_printf("rr\n");
}

void	ft_reverse(t_stack *stack, char c)
{
	t_list	*list;

	if (stack ->size <= 1)
		return ;
	list = stack ->head;
	while (list ->next ->next)
		list = list ->next;
	list ->next ->next = stack ->head;
	stack ->head = list ->next;
	list ->next = NULL;
	if (c)
		ft_printf("rr%c\n", c);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse(stack_a, 0);
	ft_reverse(stack_b, 0);
	ft_printf("rrr\n");
}
