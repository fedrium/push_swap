/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:59:43 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/04 13:21:57 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	char	*str;

	i = ft_strlen_gnl((char *)s1);
	j = ft_strlen_gnl((char *)s2);
	k = -1;
	l = 0;
	str = malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	while (++k < i)
		str[k] = s1[k];
	while (l < j)
	{
		str[k] = s2[l];
		k++;
		l++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		k;
	char	*str;

	i = ft_strlen_gnl((char *)s1);
	k = 0;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (s1[k] != '\0')
	{
		str[k] = s1[k];
		k++;
	}
	str[k] = '\0';
	return ((char *)&str[0]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == 0)
		return (0);
	if (start >= ft_strlen_gnl(s))
		len = 0;
	else if (start + len >= ft_strlen_gnl(s))
		len = ft_strlen_gnl(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (len > i && s[start] != '\0')
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	ft_strchr(const char *str, int chr)
{
	int		i;
	char	c;
	char	*s;

	if (str == 0)
		return (0);
	i = 0;
	c = chr;
	s = (char *)str;
	if (chr == '\0')
		return (s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (chr == '\0')
		{
			if (s[i + 1] == '\0')
				return (s[i + 1]);
		}
		if (s[i] == c)
			return (s[i]);
		i++;
	}
	return (0);
}
