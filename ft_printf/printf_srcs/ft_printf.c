/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:33:16 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/05 13:33:16 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int	switch_format(va_list args, char format)
{
	if (format == 'd' || format == 'i')
		return (printnbr(va_arg(args, int)));
	else if (format == 's')
		return (printstr(va_arg(args, char *)));
	else if (format == 'c')
		return (printchar(va_arg(args, int)));
	else if (format == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (format == 'x' || format == 'X')
		return (print_hex(va_arg(args, unsigned int), format));
	else if (format == 'u')
		return (print_uint(va_arg(args, unsigned int)));
	else if (format == '%')
		return (printchar('%'));
	else
		return (0);
}

int	ft_printf(const char *txt, ...)
{
	va_list		args;
	int			length;

	va_start(args, txt);
	length = 0;
	while (*txt != '\0')
	{
		if (*txt == '%' && *(txt + 1) != '\0')
		{
			txt++;
			length += switch_format(args, *txt);
		}
		else
		{
			write(1, txt, 1);
			length++;
		}
		txt++;
	}
	va_end(args);
	return (length);
}
