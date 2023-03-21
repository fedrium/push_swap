/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:54:07 by bocal             #+#    #+#             */
/*   Updated: 2023/01/14 16:58:36 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	order_check(t_block *sta, int argc)
{
	int	i;

	// printf("working\n");
	// i = 0;
	// while (i < argc - 1)
	// {
	// 	printf("I: %i\n",sta[i].parti);
	// 	if (sta[i].parti > 2147483647)
	// 		return (1);
	// 	if (sta[i].parti < -2147483646)
	// 		return (1);
	// 	i++;
	// }
	i = 0;
	while (i < argc - 2)
	{
		if (sta[i].parti > sta[i + 1].parti)
			return (0);
		i++;
	}
	exit (0);
}

int	solve_check(t_stacks *stacks, t_block *sta)
{
	int	i;

	i = 0;
	while (i < stacks->anum - 1)
	{
		if (sta[i].parti < sta[i + 1].parti)
			return (0);
		i++;
	}
	return (1);
}

int dupe_check(t_block *sta, t_stacks stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks.anum)
	{
		j = i + 1;
		while(j < stacks.anum)
		{
			if (sta[i].parti == sta[j].parti)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}