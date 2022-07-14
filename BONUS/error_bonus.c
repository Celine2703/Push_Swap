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

#include "push_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_trans(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			new[j++] = str[i];
		i++;
	}
	while (str[i] == '0' && str[i + 1])
		i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = 0;
	return (new);
}

int	ft_dup(t_stack *stack, char *str)
{
	t_list	*list;
	int		content;

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

int	ft_char(char *str, t_stack *stack)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_int(char *str, t_stack *stack)
{
	char	*integer;
	char	*itoa;

	integer = ft_trans(str);
	itoa = ft_itoa(ft_atoi(str));
	if (itoa[0] == '0' && integer[0] == '-' && !ft_strcmp(integer + 1, itoa))
	{
		free(integer);
		free(itoa);
		return (0);
	}
	else if (ft_strcmp(integer, itoa))
	{
		write(2, "Error\n", 6);
		free(integer);
		free(itoa);
		ft_lstclear(stack);
		return (1);
	}
	free(integer);
	free(itoa);
	return (0);
}
