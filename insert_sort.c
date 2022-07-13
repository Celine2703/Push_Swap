/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:34:24 by cmartin-          #+#    #+#             */
/*   Updated: 2022/07/13 10:34:28 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
		ft_rr(stacka, stackb);
	while ((elem ->mov.rrr)--)
		ft_rrr(stacka, stackb);
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
