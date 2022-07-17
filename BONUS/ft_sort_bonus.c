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
	else
		return (ft_instruction(stacka, stackb));
}

void	ft_sort(t_stack *stacka, t_stack *stackb)
{
	char	*line;

	if (stacka ->size < 1)
		return ;
	line = get_next_line(STDIN_FILENO);
	while (line && stacka)
	{
		ft_do(line, stacka, stackb);
		free(line);
		line = 0;
		line = get_next_line(STDIN_FILENO);
	}
	if (line)
		free(line);
	line = 0;
}

void	ft_recup(char **str, t_stack *stack)
{
	int	i;

	if (!str || !(*str) || !(**str))
	{
		write(2, "Error\n", 6);
		return ;
	}
	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (ft_dup(stack, str[i]) || ft_char(str[i], stack)
			|| ft_int(str[i], stack))
			return ;
		ft_push(ft_lstnew(ft_atoi(str[i--])), stack);
	}
	ft_strclear(str);
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
		{
			if (ft_dup(&stacka, argv[argc]) || ft_char(argv[argc], &stacka)
				|| ft_int(argv[argc], &stacka))
				return (0) ;
			ft_push(ft_lstnew(ft_atoi(argv[argc])), &stacka);
		}
	ft_sort(&stacka, &stackb);
	if (stacka.size < 1)
		return (0);
	if (ft_verif(&stacka) && stackb.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stackb);
	ft_lstclear(&stacka);
}
