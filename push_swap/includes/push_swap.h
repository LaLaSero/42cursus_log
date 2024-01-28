/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:31:06 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/22 19:16:05 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}				t_stack;

int		check_arg(int argc, char **argv);
t_stack	*init_stack(int argc, char **argv, t_stack **stack);
void	swap(t_stack **stack, char *str);
void	push(t_stack **stack_from, t_stack **stack_to, char *str);
void	rotate(t_stack **stack, char *str);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int max_size);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack **stack, t_stack *tmp);
void	ft_stackclear(t_stack **stack);
int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);
void	free_tab(char **tab);
int		is_numerial(char **argv);

#endif