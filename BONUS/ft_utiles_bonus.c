/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:24:01 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/03 16:24:03 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_strclear(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = 0;
}

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list) * 1);
	if (elem == 0)
		return (0);
	elem ->content = content;
	elem ->next = 0;
	return (elem);
}

void	ft_lstclear(t_stack *stack)
{
	t_list	*temp;

	if (!stack)
		return ;
	while (stack ->head)
	{
		temp = stack ->head ->next;
		stack ->head ->content = 0;
		stack ->head ->next = 0;
		free(stack ->head);
		stack ->head = temp;
	}
}

int	ft_verif(t_stack *stack)
{
	t_list	*list;

	list = stack ->head;
	while (list && list ->next)
	{
		if (list ->content > list -> next ->content)
			return (0);
		list = list ->next;
	}
	return (1);
}
