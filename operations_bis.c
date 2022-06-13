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

void	ft_r(t_stack *stack) //prend elem du dessus pour le mettre en dessous
{
	t_list	*list;

	if (stack ->size <= 1)
		return ;
	list = stack ->head;
	while (list ->next)
		list = list ->next;
	list ->next = ft_pop(stack);
	list ->next ->next = NULL;
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b) //rotate pour les 2
{
	ft_r(stack_a);
	ft_r(stack_b);
}

void	ft_reverse(t_stack *stack) //prend elem du dessous pour le mettre au dessus
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
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b) //reverse les 2
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
}
