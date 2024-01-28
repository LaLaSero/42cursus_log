/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:36:48 by yutakagi          #+#    #+#             */
/*   Updated: 2023/11/22 19:19:43 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 無効な引数のとき、0を返す。
static int	ft_atoi_kai(const char *string)
{
	int	flag;
	int	result;

	while (*string == ' ' || *string == '\t' || *string == '\n'
		|| *string == '\v' || *string == '\f' || *string == '\r')
		string++;
	flag = 1;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			flag *= -1;
		string++;
	}
	result = 0;
	while (*string >= '0' && *string <= '9')
	{
		if (result * flag > INT_MAX / 10
			|| (result * flag == INT_MAX / 10 && *string - '0' > 7))
			return (0);
		if (result * flag < INT_MIN / 10
			|| (result * flag == INT_MIN / 10 && *string - '0' > 8))
			return (0);
		result = result * 10 + (*string++ - '0');
	}
	return (result * flag);
}

static int	is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] == '\0')
		return (1);
	return (0);
}

// 重複があるかどうかを判定している。
static int	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi_kai(argv[i]) == ft_atoi_kai(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// if (is_zero(argv[i]) == 0 && ft_atoi_kai(argv[i]) == 0)
// の部分で、不正な引数かどうかを判定している。
// この部分は、ft_atoi_kai(argv[i]) == 0の部分だけだと、+0,0,-0の場合がだめ。
static int	check_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (is_zero(argv[i]) == 0 && ft_atoi_kai(argv[i]) == 0)
			return (0);
		i++;
	}
	return (check_dup(argv));
}

int	check_arg(int argc, char **argv)
{
	char	**tmp;
	int		is_valid;

	if (argc < 2 || argv[1] == NULL)
		return (0);
	if (is_numerial(argv) == 0)
		return (0);
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		is_valid = check_argv(tmp);
		free_tab(tmp);
	}
	else
	{
		tmp = argv;
		tmp = &argv[1];
		is_valid = check_argv(tmp);
	}
	return (is_valid);
}
