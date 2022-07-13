/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:28:50 by cmartin-          #+#    #+#             */
/*   Updated: 2022/07/11 09:28:53 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_min(t_stack *stack)
{
	int		min;
	int		cpt;
	int		ra;
	t_list	*list;

	list = stack ->head;
	min = list ->content;
	cpt = 0;
	ra = 0;
	while (list)
	{
		if (list ->content < min)
		{
			min = list ->content;
			ra = cpt;
		}
		list = list ->next;
		cpt ++;
	}
	return (ra);
}

void	ft_init_mov(t_mov *elem)
{
	elem ->ra = 0;
	elem ->rb = 0;
	elem ->rr = 0;
	elem ->rra = 0;
	elem ->rrb = 0;
	elem ->rrr = 0;
	elem ->tot = 0;
}

void	ft_mov_b(t_stack *stack, t_list *elem, size_t pos)
{
	if (pos > (stack ->size) / 2)
		elem ->mov.rrb = (stack ->size) - pos;
	else
		elem ->mov.rb = pos;
}

void	ft_mov_a(t_stack *stack, t_list *elem)
{
	int		cpt;
	int		max;
	t_list	*list;

	list = stack ->head;
	max = list ->content;
	cpt = 0;
	while (list)
	{
		if (list ->content > elem ->content && (list ->content < max
				|| max < elem ->content))
		{
			max = list ->content;
			elem ->mov.ra = cpt;
		}
		list = list ->next;
		cpt ++;
	}
	if (elem ->content > max)
		elem ->mov.ra = ft_min(stack);
	if ((size_t)(elem ->mov.ra) > (stack ->size) / 2)
	{
		elem ->mov.rra = (stack ->size) - elem ->mov.ra;
		elem ->mov.ra = 0;
	}
}

void	ft_mov_rr(t_list *elem)
{
	if (elem ->mov.ra && elem ->mov.rb)
	{
		if (elem ->mov.ra >= elem ->mov.rb)
		{
			elem ->mov.ra = elem ->mov.ra - elem ->mov.rb;
			elem ->mov.rr = elem ->mov.rb;
			elem ->mov.rb = 0;
		}
		else
		{
			elem ->mov.rb = elem ->mov.rb - elem ->mov.ra;
			elem ->mov.rr = elem ->mov.ra;
			elem ->mov.ra = 0;
		}
	}
}
