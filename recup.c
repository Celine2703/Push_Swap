/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:16:31 by cmartin-          #+#    #+#             */
/*   Updated: 2022/06/13 11:16:34 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*some arguments are
bigger than an integer */

#include "push.h"

void	ft_strclear(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
	str = 0;
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
		{
			ft_strclear(str);
			return ;
		}
		ft_push(ft_lstnew(ft_atoi(str[i--])), stack);
	}
	ft_strclear(str);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.head = 0;
	stack.size = 0;
	if (argc <= 1)
		return (0);
	if (argc == 2)
		ft_recup(ft_split(argv[1], ' '), &stack);
	else
	{
		while (argc-- > 1)
		{
			if (ft_dup(&stack, argv[argc]) || ft_char(argv[argc], &stack)
				|| ft_int(argv[argc], &stack))
				break ;
			ft_push(ft_lstnew(ft_atoi(argv[argc])), &stack);
		}
	}
	if (stack.size <= 1)
		return (ft_lstclear(&stack), 0);
	ft_put_pos(&stack);
	if (!ft_verif(&stack))
		ft_sort(&stack);
	ft_lstclear(&stack);
}
