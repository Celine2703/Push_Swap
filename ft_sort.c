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

void	ft_sort_three(t_stack *stack)
{
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