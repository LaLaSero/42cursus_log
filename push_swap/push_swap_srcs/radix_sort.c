/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 00:35:07 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/17 16:36:23 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	connect_btoa(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	max_size;

	max_size = ft_stacksize(*stack_b);
	i = 0;
	while (i < max_size)
	{
		push(stack_b, stack_a, "pa");
		i++;
	}
}

// tmp=tmp->nextでやるとバグる
// rotate,swapされるため、最初の要素だけ見れば良い
void	radix_sort(t_stack **stack_a, t_stack **stack_b, int max_size)
{
	int	i;
	int	j;
	int	index;
	int	max_bit_digit;

	max_bit_digit = 0;
	while ((max_size >> max_bit_digit) != 0)
		max_bit_digit++;
	i = 0;
	while (i < max_bit_digit)
	{
		j = 0;
		while (j < max_size)
		{
			index = (*stack_a)->index;
			if (((index >> i) & 1) == 1)
				rotate(stack_a, "ra");
			else
				push(stack_a, stack_b, "pb");
			j++;
		}
		connect_btoa(stack_a, stack_b);
		i++;
	}
}
