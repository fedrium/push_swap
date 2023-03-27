/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:53:03 by cyu-xian          #+#    #+#             */
/*   Updated: 2022/08/19 15:47:21 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 9999

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*trimmer(int i, char *buffer);
size_t	ft_strlen_gnl(const char *str);
char	ft_strchr(const char *str, int chr);

#endif