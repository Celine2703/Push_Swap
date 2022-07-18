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

int	ft_do(char *str, t_stack *stacka, t_stack *stackb)
{
	if (!ft_strcmp(str, "sa\n"))
		ft_s(stacka);
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
<<<<<<< HEAD
		return (1);
	return (0);
=======
		return (ft_instruction(stacka, stackb));
>>>>>>> 8617942d2527ba0232945c06fa56e893a1a85d81
}

int	ft_sort(t_stack *stacka, t_stack *stackb)
{
	char	*line;
	int	error;

	if (stacka ->size < 1)
		return ;
	line = get_next_line(STDIN_FILENO);
<<<<<<< HEAD
	error = 0;
	while (!error && line)
=======
	while (line && stacka)
>>>>>>> 8617942d2527ba0232945c06fa56e893a1a85d81
	{
		error = ft_do(line, stacka, stackb);
		free(line);
		line = 0;
		if (error)
			return (1);
		line = get_next_line(STDIN_FILENO);
	}
	if (line)
		free(line);
	line = 0;
	return (0);
}

int	ft_recup(char **str, t_stack *stack)
{
	int	i;

	if (!str || !(*str) || !(**str))
	{
		write(2, "Error\n", 6);
<<<<<<< HEAD
		return (1);
=======
		return ;
>>>>>>> 8617942d2527ba0232945c06fa56e893a1a85d81
	}
	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (ft_dup(stack, str[i]) || ft_char(str[i], stack)
			|| ft_int(str[i], stack))
<<<<<<< HEAD
			return (1);
=======
			return ;
>>>>>>> 8617942d2527ba0232945c06fa56e893a1a85d81
		ft_push(ft_lstnew(ft_atoi(str[i--])), stack);
	}
	ft_strclear(str);
	return (0);
}

int	ft_recup_bis(char	**argv, int argc, t_stack *stack)
{
	while (argc-- > 1)
	{
		if (ft_dup(stack, argv[argc]) || ft_char(argv[argc], stack)
			|| ft_int(argv[argc], stack))
			return (1);
		ft_push(ft_lstnew(ft_atoi(argv[argc])), stack);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stacka;
	t_stack	stackb;
	int		error;

	stacka.head = 0;
	stacka.size = 0;
	stackb.head = 0;
	stackb.size = 0;
	error = 0;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
		error = ft_recup(ft_split(argv[1], ' '), &stacka);
	else
<<<<<<< HEAD
		error = ft_recup_bis(argv, argc, &stacka);
	if (error || stacka.size < 1)
		return (0);
	error = ft_sort(&stacka, &stackb);
	if (error)
		write(2, "Error\n", 6);
	else if (ft_verif(&stacka) && stackb.size == 0)
=======
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
>>>>>>> 8617942d2527ba0232945c06fa56e893a1a85d81
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stackb);
	ft_lstclear(&stacka);
}
