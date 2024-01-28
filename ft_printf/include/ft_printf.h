/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:02:23 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/06 14:02:23 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

size_t	printnbr(int n);
size_t	printstr(char *s);
size_t	printchar(int c);
int		ft_printf(const char *txt, ...);
int		print_pointer(void *p);
int		print_uint(unsigned int num);
int		print_hex(unsigned int num, char format);
int		print_str(char *s);
int		print_int(int num);

#endif