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
