/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:50:32 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/28 17:44:46 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_numerial(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || '9' < argv[i][j])
			{
				if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (is_sorted(*stack_a) == 1)
		return ;
	size = ft_stacksize(*stack_a);
	if (size == 2)
		swap(stack_a, "sa");
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, size);
}
