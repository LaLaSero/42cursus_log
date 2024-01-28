/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:09:28 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/17 16:36:37 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, char *str)
{
	int	tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
	tmp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp;
	ft_putendl_fd(str, 1);
}

void	push(t_stack **stack_from, t_stack **stack_to, char *str)
{
	t_stack	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	tmp = (*stack_from)->next;
	(*stack_from)->next = *stack_to;
	*stack_to = *stack_from;
	*stack_from = tmp;
	ft_putendl_fd(str, 1);
}

void	rotate(t_stack **stack, char *str)
{
	t_stack	*head;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	tail = ft_stacklast(*stack);
	if (ft_strlen(str) == 2)
	{
		*stack = head->next;
		tail->next = head;
		head->next = NULL;
	}
	else
	{
		*stack = tail;
		tail->next = head;
		while (head->next != tail)
			head = head->next;
		head->next = NULL;
	}
	ft_putendl_fd(str, 1);
}
