/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:55:59 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/17 16:36:28 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min_index(t_stack **stack_a)
{
	int		min_index;
	t_stack	*tmp;

	tmp = *stack_a;
	min_index = INT_MAX;
	while (tmp != NULL)
	{
		if (tmp->index < min_index)
			min_index = tmp->index;
		tmp = tmp->next;
	}
	return (min_index);
}

// 一番小さいindexのスタックを先頭に持ってくる
// rraかraの処理で改善の余地あり
static void	locate_min_at_first(t_stack **stack)
{
	int	min_index;

	min_index = get_min_index(stack);
	if (ft_stacklast(*stack)->index == min_index)
		rotate(stack, "rra");
	while (stack[0]->index != min_index)
		rotate(stack, "ra");
}

void	sort_three(t_stack **stack_a)
{
	int	num1;
	int	num2;
	int	min_index;

	min_index = get_min_index(stack_a);
	num1 = (*stack_a)->index;
	num2 = (*stack_a)->next->index;
	if (num1 == min_index && num2 == min_index + 2)
	{
		rotate(stack_a, "rra");
		swap(stack_a, "sa");
	}
	else if (num1 == min_index + 1 && num2 == min_index)
		swap(stack_a, "sa");
	else if (num1 == min_index + 1 && num2 == min_index + 2)
		rotate(stack_a, "rra");
	else if (num1 == min_index + 2 && num2 == min_index)
		rotate(stack_a, "ra");
	else if (num1 == min_index + 2 && num2 == min_index + 1)
	{
		swap(stack_a, "sa");
		rotate(stack_a, "rra");
	}
	return ;
}

// sort_three(&stack_a[1], stack_b);とするとrotateでバグる
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	locate_min_at_first(stack_a);
	push(stack_a, stack_b, "pb");
	sort_three(stack_a);
	push(stack_b, stack_a, "pa");
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	locate_min_at_first(stack_a);
	push(stack_a, stack_b, "pb");
	sort_four(stack_a, stack_b);
	push(stack_b, stack_a, "pa");
}
