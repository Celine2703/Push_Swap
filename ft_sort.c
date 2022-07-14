/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:08:44 by cmartin-          #+#    #+#             */
/*   Updated: 2022/06/13 14:08:48 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_sort(t_stack *stack)
{
	if (stack ->size == 3)
		ft_sort_three(stack);
	else if (stack ->size < 20)
		ft_sort_few(stack);
	else
		ft_sort_many(stack);
}

void	ft_sort_three(t_stack *stack)
{
	ft_put_pos(stack);
	while (stack ->head && !(ft_verif(stack)))
	{
		if (stack ->head ->pos == 3)
		{
			ft_r(stack, 'a');
			ft_put_pos(stack);
		}
		if (stack ->head ->next ->pos == 3)
		{
			ft_reverse(stack, 'a');
			ft_put_pos(stack);
		}
		if (stack ->head ->next ->pos == 1)
		{
			ft_s(stack, 'a');
			ft_put_pos(stack);
		}
	}
}

void	ft_sort_few(t_stack	*stacka)
{
	t_stack	stackb;

	stackb.head = 0;
	stackb.size = 0;
	while (stacka ->size > 3 && !ft_verif(stacka))
	{
		ft_rotate(stacka);
		if (!ft_verif(stacka))
			ft_p(stacka, &stackb, 'b');
	}
	if (stacka ->size <= 3)
		ft_sort_three(stacka);
	while (stackb.size)
		ft_p(&stackb, stacka, 'a');
	ft_lstclear(&stackb);
}	

void	ft_sort_many(t_stack *stacka)
{
	t_stack	stackb;

	stackb.head = 0;
	stackb.size = 0;
	while (stacka ->head ->next)
		ft_p(stacka, &stackb, 'b');
	while (stackb.size > 0)
	{
		ft_put_mov(&stackb, stacka);
		ft_insert(stacka, &stackb, ft_pick(&stackb));
	}
	ft_rotate(stacka);
}
