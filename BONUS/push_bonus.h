/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:39:25 by cmartin-          #+#    #+#             */
/*   Updated: 2022/06/10 13:39:43 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_BONUS_H
# define PUSH_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

# define BUFFER_SIZE 10

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*head;
	size_t	size;
}	t_stack;

//GNL
int		ft_strstr(char *str);
char	*ft_strncpy(char *str, int n);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char **str, char *new);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t size, size_t espace);
char	*ft_read(char **str, int fd);
char	*get_next_line(int fd);

int		ft_strcmp(const char *s1, const char *s2);
void	ft_strclear(char **str);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_stack *stack);
int		ft_verif(t_stack *stack);

int		ft_atoi(const char *str);

char	*ft_itoa(int n);

char	**ft_split(char const *str, char const c);

//error
<<<<<<< HEAD
=======
void	ft_instruction(t_stack *stacka, t_stack *stackb);
>>>>>>> 8617942d2527ba0232945c06fa56e893a1a85d81
char	*ft_trans(char *str);
int		ft_dup(t_stack *stack, char *str);
int		ft_char(char *str, t_stack *stack);
int		ft_int(char *str, t_stack *stack);

//operations
void	ft_push(t_list *new, t_stack *stack);
t_list	*ft_pop(t_stack *stack);
void	ft_s(t_stack *stack);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_p(t_stack *stack1, t_stack *stack2);

void	ft_r(t_stack *stack);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_reverse(t_stack *stack);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

//sort
int	ft_do(char *str, t_stack *stacka, t_stack *stackb);
int	ft_sort(t_stack *stacka, t_stack *stackb);
int		ft_recup(char **str, t_stack *stack);
int		ft_recup_bis(char	**argv, int argc, t_stack *stack);

#endif
