/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:40 by cmartin-          #+#    #+#             */
/*   Updated: 2022/06/10 15:27:42 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

void	ft_push(t_list *new, t_stack *stack)
{
	if (!stack || !new)
		return ;
	new ->next = stack ->head;
	stack ->head = new;
	stack ->size += 1;
}

t_list	*ft_pop(t_stack *stack)
{
	t_list	*temp;

	temp = stack ->head;
	stack ->head = stack ->head ->next;
	stack ->size -= 1;
	return (temp);
}

void	ft_s(t_stack *stack)
{
	t_list	*temp1;
	t_list	*temp2;

	if (stack ->size <= 1)
		return ;
	temp1 = stack ->head;
	stack ->head = stack ->head ->next;
	temp2 = stack ->head ->next;
	stack ->head ->next = temp1;
	temp1 ->next = temp2;
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
}

void	ft_p(t_stack *stack1, t_stack *stack2)
{
	ft_push(ft_pop(stack1), stack2);
}
