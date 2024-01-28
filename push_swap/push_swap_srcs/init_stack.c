/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:26:01 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/17 16:36:04 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 各構造体のnumの大小関係に基づいてindexを割り振る
// 1から始まる
static void	alloc_index(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = *stack_a;
	while (current != NULL)
	{
		compare = *stack_a;
		index = 1;
		while (compare != NULL)
		{
			if (current->num > compare->num)
				index++;
			compare = compare->next;
		}	
		current->index = index;
		current = current->next;
	}
}

t_stack	*init_stack(int n, char **argv, t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	ft_stackadd_back(stack_a, ft_stacknew(ft_atoi(argv[i])));
	if (*stack_a == NULL)
		return (NULL);
	tmp = *stack_a;
	while (i < n - 1)
	{
		tmp = ft_stacknew(ft_atoi(argv[i + 1]));
		if (tmp == NULL)
		{
			ft_stackclear(stack_a);
			return (NULL);
		}
		ft_stackadd_back(stack_a, tmp);
		tmp = tmp->next;
		i++;
	}
	alloc_index(stack_a);
	return (*stack_a);
}
