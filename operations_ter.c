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
