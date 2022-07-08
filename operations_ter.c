/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:48:18 by cmartin-          #+#    #+#             */
/*   Updated: 2022/06/13 13:48:19 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_put_pos(t_stack *stack)
{
	t_list	*list;

	list = stack ->head;
	while (list)
	{
		list ->pos = ft_pos(stack, list);
		list = list ->next;
	}
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

	if (pos >= (stack ->size) / 2)
		elem ->mov.rrb = pos - ((stack ->size) / 2);
	elem ->mov.rb = pos;
}

int	ft_mov_a(t_stack *stack, t_list *elem)
{
	int		cpt;
	int		max;
	t_list	*list;
	
	list = stack ->head;
	max = list ->content;
	cpt = 0;
	while (list)
	{
		if (list ->content < max && list ->content > elem ->content)
		{
			max = list ->content;
			elem ->mov.ra = cpt;
		}
		list = list ->next;
		cpt ++;
	}
	if (elem ->mov.ra >= (stack ->size) / 2)
	{
		elem ->mov.rra = elem ->mov.ra - ((stack ->size) / 2);
		elem ->mov.ra = 0;
		return (elem ->mov.rra);
	}
	return (elem ->mov.ra);

int	ft_mov_a(t_stack *stack, t_list *elem)
{
	size_t	pos;

	pos = ft_pos(stack, elem);
	if (pos <= (stack ->size) / 2)
	{
		while (pos != 0)
		{
			elem ->mov.ra ++;
			pos --;
		}
		return (elem ->mov.ra);
	}
	else
	{
		while (pos != 0)
		{
			elem ->mov.rra ++;
			pos --;
		}
		return (elem ->mov.rra);
	}
}

void	ft_put_mov(t_stack *stackb, t_stack *stacka)
{
	t_list	*list;
	int		cpt;

	list = stackb ->head;
	cpt = 0;
	while (list)
	{
		list ->mov = ft_mov_b(stackb, list, cpt) + ft_mov_a() + 1;
		list = list ->next;
		cpt ++;
	}
}

int	ft_verif(t_stack *stack)
{
	t_list	*list;

	list = stack ->head;
	while (list && list ->next)
	{
		if (list ->pos > list -> next ->pos)
			return (0);
		list = list ->next;
	}
	return (1);
}
