/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:48:18 by cmartin-          #+#    #+#             */
/*   Updated: 2022/06/13 13:48:19 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_pos(t_stack *stack, t_list *elem)
{
	t_list	*list;
	int		pos;

	list = stack ->head;
	pos = 1;
	while (list)
	{
		if (elem ->content > list ->content)
			pos += 1;
		list = list ->next;
	}
	return (pos);
}

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
