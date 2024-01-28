/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:13:54 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/05 15:13:54 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

size_t	printnbr(int n)
{
	size_t	len;
	char	*str;

	ft_putnbr_fd(n, 1);
	str = ft_itoa(n);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	printstr(char *s)
{
	if (s == NULL)
		return (printstr("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

size_t	printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_uint(unsigned int num)
{
	int	length;
	int	nums[10];
	int	i;

	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	length = 0;
	while (num > 0)
	{
		nums[length] = num % 10;
		num /= 10;
		length++;
	}
	i = length;
	while (i > 0)
	{
		ft_putnbr_fd(nums[i - 1], 1);
		i--;
	}
	return (length);
}
