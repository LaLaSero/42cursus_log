/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:03:06 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/17 16:36:09 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new -> num = content;
	new -> index = 0;
	new -> next = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last_p;

	if (new == NULL)
		return ;
	last_p = ft_stacklast(*stack);
	if (last_p == NULL)
		*stack = new;
	else
		last_p -> next = new;
	return ;
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL)
	{
		return ;
	}
	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*last_p;

	if (stack == NULL)
		return (NULL);
	last_p = stack;
	while (last_p -> next != NULL)
		last_p = last_p -> next;
	return (last_p);
}
