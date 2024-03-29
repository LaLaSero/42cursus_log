/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yutakagi <yutakagi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:37:55 by yutakagi          #+#    #+#             */
/*   Updated: 2023/10/18 16:52:25 by yutakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE	
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char*s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t dst_size);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

#endif