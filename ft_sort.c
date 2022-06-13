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
	t_list	list;

	list = stack ->head;
	while (list)
	{
		if (list.content < list.next -> 
		
}

t_list	*ft_min(t_stack *stack)
{
	int	min;
	t_list	*list;

	list = stack ->head;
	min = list ->content;
	elem = list;
	while (list)
	{
		if (list ->content < min)
		{
			min = list ->content;
			elem = list;
		}
	list = list ->next;
	}
	return (list);
}
(t_stack stack)
{
	t_list	*list;
	t_stack new_stack;

	list = new_stack.head;
	while (list)
	{
		*list = 
		list = list.next;
	}
}
int	ft_middle(t_stack *stack);
{
	
