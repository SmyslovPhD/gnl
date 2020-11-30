/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 01:49:45 by kbraum            #+#    #+#             */
/*   Updated: 2020/11/30 21:31:54 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *s)
{
	size_t register	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char const *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i <= s_len)
		if ((unsigned char)s[i++] == (unsigned char)c)
			return ((char*)&s[i - 1]);
	return (0);
}

char	*ft_strcpy(char *dst, char const *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	j = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (j)
	{
		i = 0;
		while (*s1)
			j[i++] = *(s1++);
		while (*s2)
			j[i++] = *(s2++);
		j[i] = '\0';
	}
	return (j);
}
