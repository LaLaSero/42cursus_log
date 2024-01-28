/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:33:42 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/22 19:09:19 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	display_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	count_str(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

// init_stackは引数の数(1始まり)、引数のポインタ配列(0始まり)を受け取る。
// // push_swap後は先頭にあったstackがどこにあるかわからない。
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tmp;

	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) == 0)
		return (display_error());
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		stack_a = init_stack(count_str(argv[1], ' '), tmp, &stack_a);
		free_tab(tmp);
	}
	else
		stack_a = init_stack(argc - 1, &argv[1], &stack_a);
	if (stack_a == NULL)
		return (display_error());
	push_swap(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
