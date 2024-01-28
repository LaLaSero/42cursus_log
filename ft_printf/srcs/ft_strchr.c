/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:24:15 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/18 13:19:16 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = (char *)s;
	if (c == '\0')
		return (p + ft_strlen(p));
	while (p[i] != '\0')
	{
		if (p[i] == (char)c)
			return (p + i);
		i++;
	}
	return (NULL);
}
