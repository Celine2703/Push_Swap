/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:44:45 by cmartin-          #+#    #+#             */
/*   Updated: 2022/07/14 11:44:47 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_dup(t_stack *stack, char *str)
{
	t_list	*list;
	int	content;

	if (!str || !(str[0]))
	{
		write(2, "Error\n", 6);
		ft_lstclear(stack);
		return (1);
	}
	list = stack ->head;
	content = ft_atoi(str);
	while (list)
	{
		if (list ->content == content)
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack);
			return (1);
		}
		list = list ->next;
	}
	return (0);
}
