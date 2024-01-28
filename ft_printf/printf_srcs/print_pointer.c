/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:14:11 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/05 22:14:11 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

int	count_digit_dum(uintptr_t n, char *base)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		len++;
		n /= (int)ft_strlen(base);
	}
	return (len);
}

char	*uint_to_str(uintptr_t n, char *str, int len, char *base)
{
	int			i;
	uintptr_t	digit;

	i = 0;
	if (n == 0)
		str[i++] = base[0];
	else
	{
		i = 0;
		while (n > 0)
		{
			digit = n % (uintptr_t)ft_strlen(base);
			str[len - 1 - i] = base[digit];
			n /= (uintptr_t)ft_strlen(base);
			i++;
		}
	}
	str[len] = '\0';
	return (str);
}

char	*uintptrtoa_base(uintptr_t n, char *base)
{
	char	*str;
	int		len;

	len = count_digit_dum(n, base);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', len + 1);
	return (uint_to_str(n, str, len, base));
}

int	print_pointer(void *p)
{
	uintptr_t	address_num;
	char		*address_str;
	int			length;

	address_num = (uintptr_t)p;
	ft_putstr_fd("0x", 1);
	address_str = uintptrtoa_base(address_num, "0123456789abcdef");
	ft_putstr_fd(address_str, 1);
	length = ft_strlen(address_str) + 2;
	free(address_str);
	return (length);
}
