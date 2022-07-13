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
	write(1, "\n", 1);
}

void	ft_affiche_mov(t_list	*list)
{
	ft_putnbr_fd(list ->mov.ra, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(list ->mov.rb, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(list ->mov.rr, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(list ->mov.rra, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(list ->mov.rrb, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(list ->mov.rrr, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(list ->mov.tot, 1);
	write(1, "\n\n", 2);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.head = 0;
	stack.size = 0;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
		ft_recup(ft_split(argv[1], ' '), &stack);
	else
		while (argc-- > 1)
			ft_push(ft_lstnew(ft_atoi(argv[argc])), &stack);
	if (stack.size <= 1)
		return (0);
	ft_put_pos(&stack);
	if (!ft_verif(&stack))
		ft_sort(&stack);
}

//write(2, "Error\n", 6);
