/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:21:00 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/06 12:21:00 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int	count_digit_hex(unsigned int num)
{
	int	length;

	length = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		length++;
		num /= 16;
	}
	return (length);
}

int	print_hex(unsigned int num, char format)
{
	int	length;

	length = count_digit_hex(num);
	if (num >= 16)
		print_hex(num / 16, format);
	if (num % 16 < 10)
	{
		ft_putnbr_fd(num % 16, 1);
	}
	else if (format == 'x' && num % 16 >= 10)
	{
		ft_putchar_fd((num % 16) - 10 + 'a', 1);
	}
	else if (format == 'X' && num % 16 >= 10)
		ft_putchar_fd((num % 16) - 10 + 'A', 1);
	return (length);
}
