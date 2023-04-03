/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:28:08 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 16:28:51 by cyu-xian         ###   ########.fr       */
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

void	twoargc(char *str, t_block *sta, t_block *stb, t_stacks stacks)
{
	int	len;

	len = cnt_word(str, ' ') + 1;
	// free(sta);
	// free(stb);
	sta = malloc(sizeof(t_block) * len);
	stb = malloc(sizeof(t_block) * len);
	if (spliter(sta, str, &stacks) == 1)
		error(sta, stb);
	if (dupe_check(sta, stacks) == 1)
		error(sta, stb);	
}