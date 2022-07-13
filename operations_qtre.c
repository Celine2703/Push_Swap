/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_qtre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:28:50 by cmartin-          #+#    #+#             */
/*   Updated: 2022/07/11 09:28:53 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_mov_rrr(t_list *elem)
{
	if (elem ->mov.rra && elem ->mov.rrb)
	{
		if (elem ->mov.rra >= elem ->mov.rrb)
		{
			elem ->mov.rra = elem ->mov.rra - elem ->mov.rrb;
			elem ->mov.rrr = elem ->mov.rrb;
			elem ->mov.rrb = 0;
		}
		else
		{
			elem ->mov.rrb = elem ->mov.rrb - elem ->mov.rra;
			elem ->mov.rrr = elem ->mov.rra;
			elem ->mov.rra = 0;
		}
	}
}

void	ft_mov_add(t_stack *stackb, t_stack *stacka, t_list *elem, int cpt)
{
	ft_mov_b(stackb, elem, cpt);
	ft_mov_a(stacka, elem);
	ft_mov_rr(elem);
	ft_mov_rrr(elem);
	elem ->mov.tot = elem ->mov.ra + elem ->mov.rb + elem ->mov.rra
		+ elem ->mov.rrb + elem ->mov.rr + elem ->mov.rrr;
}	

void	ft_put_mov(t_stack *stackb, t_stack *stacka)
{
	t_list	*list;
	size_t	cpt;

	list = stackb ->head;
	cpt = 0;
	while (list)
	{
		ft_init_mov(&(list ->mov));
		ft_mov_add(stackb, stacka, list, cpt);
		list = list ->next;
		cpt ++;
	}
}

t_list	*ft_pick(t_stack *stack)
{
	t_list	*list;
	t_list	*min;

	list = stack ->head;
	min = list;
	while (list)
	{
		if (list ->mov.tot < min ->mov.tot)
			min = list;
		list = list ->next;
	}
	return (min);
}

void	ft_insert(t_stack *stacka, t_stack *stackb, t_list *elem)
{
	while ((elem ->mov.rr)--)
	{
		ft_r(stackb, 'b');
		ft_r(stacka, 'a');
	}
	while ((elem ->mov.rrr)--)
	{
		ft_reverse(stackb, 'b');
		ft_reverse(stacka, 'a');
	}
	while ((elem ->mov.rb)--)
		ft_r(stackb, 'b');
	while ((elem ->mov.rrb)--)
		ft_reverse(stackb, 'b');
	while ((elem ->mov.ra)--)
		ft_r(stacka, 'a');
	while ((elem ->mov.rra)--)
		ft_reverse(stacka, 'a');
	ft_p(stackb, stacka, 'a');
}

void	ft_rotate(t_stack *stack)
{
	int	ra;
	int	rra;
	
	ra = ft_min(stack);
	rra = 0;
	if (ra > (int)((stack ->size) / 2))
	{
		rra = (stack ->size) - ra;
		ra = 0;
	}
	while (ra--)
		ft_r(stack, 'a');
	while (rra--)
		ft_reverse(stack, 'a');
}
