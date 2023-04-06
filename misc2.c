/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:28:08 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/04 16:49:27 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	median_helper(int *temp, int temptwo, int pushed)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < pushed)
	{
		j = 0;
		while (j + 1 < pushed)
		{
			if (temp[j] > temp[j + 1])
			{
				temptwo = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = temptwo;
			}
			j++;
		}
		i++;
	}
}

void	error(t_block *sta, t_block *stb)
{
	free(sta);
	free(stb);
	write(2, "Error\n", 6);
	exit(0);
}

void	twoargc(char *str, t_block *sta, t_block *stb, t_stacks *stacks)
{
	if (spliter(sta, str, stacks) == 1)
		error(sta, stb);
	if (dupe_check(sta, *stacks) == 1)
		error(sta, stb);
}

int	spliter(t_block *sta, char *str, t_stacks *stacks)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	array = ft_split(str, ' ');
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j]) == 1)
				return (1);
			j++;
		}
		sta[i].parti = ft_atoi(array[i]);
		if (sta[i].parti > 2147483647 || sta[i].parti < -2147483648)
			return (1);
		i++;
	}
	freeing(array);
	stacks->anum = i;
	return (0);
}

void	freeing(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
}
