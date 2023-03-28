/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:16:00 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/08/23 14:09:43 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_finder(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' )
		i++;
	return (i);
}

int	null_checker(char *buffer)
{
	if (buffer == NULL)
		return (0);
	if (buffer[0] == '\0')
	{
		free(buffer);
		return (0);
	}
	return (1);
}

char	*helper(int fd, char *buffer)
{
	int		num;
	char	book[BUFFER_SIZE + 1];
	char	*temp;

	num = read(fd, book, BUFFER_SIZE);
	while (num > 0)
	{
		book[num] = '\0';
		if (buffer == NULL)
			buffer = ft_strdup(book);
		else
		{
			temp = ft_strjoin(buffer, book);
			free (buffer);
			buffer = temp;
		}
		if (ft_strchr(buffer, '\n') != 0)
			break ;
		num = read(fd, book, BUFFER_SIZE);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	char		*ret;

	if (!buffer)
		buffer = NULL;
	ret = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = helper(fd, buffer);
	if (null_checker(buffer) == 0)
		return (NULL);
	if (ft_strchr(buffer, '\n') != 0)
	{
		ret = ft_substr(buffer, 0, new_line_finder(buffer) + 1);
		temp = ft_strdup(buffer + new_line_finder(buffer) + 1);
		free (buffer);
		buffer = temp;
	}
	else
	{
		ret = buffer;
		buffer = NULL;
	}
	return (ret);
}
