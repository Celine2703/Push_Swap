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

/*In case of error, it must display "Error" 
followed by a ’\n’ on the standard error.
Errors include for example: some arguments 
aren’t integers, some arguments are
bigger than an integer and/or there are duplicates*/

#include <stdio.h>
#include "push.h"

void	ft_affiche(t_stack *stack)
{
	t_list	*list;

	list = stack ->head;
	while (list)
	{
		ft_putnbr_fd(list ->pos, 1);
		write(1, "\n", 1);
		list = list ->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**str;
	int		i;

	stack.head = 0;
	stack.size = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		i = 0;
		while (str[i])
			i++;
		i--;
		while (i >= 0)
			ft_push(ft_lstnew(ft_atoi(str[i--])), &stack);
	}
	else
		while (argc-- > 1)
			ft_push(ft_lstnew(ft_atoi(argv[argc])), &stack);
	if (stack.size <= 1)
		return (0);
	ft_put_pos(&stack);
	if (!ft_verif(&stack))
	{
		ft_sort_three(&stack);
		//ft_affiche(&stack);
	}
}

//write(2, "Error\n", 6);
