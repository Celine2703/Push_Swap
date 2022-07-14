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

#include "push.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb = nb % 10;
	}
	if ((nb >= 0) && (nb <= 9))
		ft_putchar_fd(nb + 48, fd);
}

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list) * 1);
	if (elem == 0)
		return (0);
	elem ->content = content;
	elem ->next = 0;
	elem ->pos = -1;
	ft_init_mov(&(elem ->mov));
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
		if (list ->pos > list -> next ->pos)
			return (0);
		list = list ->next;
	}
	return (1);
}
