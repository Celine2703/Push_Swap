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

#include "push_bonus.h"

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

void	ft_affiche(t_stack *stack)
{
	t_list	*list;

	list = stack ->head;
	while (list)
	{
		ft_putnbr_fd(list ->content, 1);
		write(1, "\n", 1);
		list = list ->next;
	}
	write(1, "\n", 1);
}

void	ft_do(char *str, t_stack *stacka, t_stack *stackb)
{
	if (!ft_strcmp(str, "sa\n"))
		ft_s(stacka);
	else if (!ft_strcmp(str, "sb\n"))
		ft_s(stackb);
	else if (!ft_strcmp(str, "sb\n"))
		ft_s(stackb);
	else if (!ft_strcmp(str, "ss\n"))
		ft_ss(stacka, stackb);
	else if (!ft_strcmp(str, "pa\n"))
		ft_p(stackb, stacka);
	else if (!ft_strcmp(str, "pb\n"))
		ft_p(stacka, stackb);
	else if (!ft_strcmp(str, "ra\n"))
		ft_r(stacka);
	else if (!ft_strcmp(str, "rb\n"))
		ft_r(stackb);
	else if (!ft_strcmp(str, "rr\n"))
		ft_rr(stacka, stackb);
	else if (!ft_strcmp(str, "rra\n"))
		ft_reverse(stacka);
	else if (!ft_strcmp(str, "rrb\n"))
		ft_reverse(stackb);
	else if (!ft_strcmp(str, "rrr\n"))
		ft_rrr(stacka, stackb);
}

void	ft_sort(t_stack *stacka, t_stack *stackb)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		ft_do(line, stacka, stackb);
		line = get_next_line(STDIN_FILENO);
	}
}

void	ft_recup(char **str, t_stack *stack)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
		ft_push(ft_lstnew(ft_atoi(str[i--])), stack);
}

int	main(int argc, char **argv)
{
	t_stack	stacka;
	t_stack	stackb;

	stacka.head = 0;
	stacka.size = 0;
	stackb.head = 0;
	stackb.size = 0;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
		ft_recup(ft_split(argv[1], ' '), &stacka);
	else
		while (argc-- > 1)
			ft_push(ft_lstnew(ft_atoi(argv[argc])), &stacka);
	if (stacka.size < 1)
		return (0);
	ft_sort(&stacka, &stackb);
	if (ft_verif(&stacka) && stackb.size == 0)
		write(1, "OK\n", 2);
}
