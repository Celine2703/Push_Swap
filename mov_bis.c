/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:28:23 by cmartin-          #+#    #+#             */
/*   Updated: 2022/07/13 10:32:48 by cmartin-         ###   ########.fr       */
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
