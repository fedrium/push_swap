/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:33:38 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/05 17:57:52 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checking(t_block *sta, t_stacks stacks, char **argv)
{
	if (symbol_check(argv) == 1
		|| converter(sta, argv, &stacks) == 1
		|| dupe_check(sta, stacks) == 1)
		return (1);
	return (0);
}

void	freer(t_block *sta, t_block *stb)
{
	free(sta);
	free(stb);
}

void	fivesolve(t_block *sta, t_block *stb, t_stacks stacks)
{
	int	median;
	int	i;

	i = 0;
	median = median_finder_a(sta, 5);
	while (i < 5)
	{
		if (sta[i].parti < median)
			pa(sta, stb, &stacks);
		else
			ra(sta, &stacks);
	}
	if (stacks.anum == 3)
	{
		solverah(sta, stacks, 3);
		solverbh(sta, stb, stacks, 2);
	}
	else
	{
		solverah(sta, stacks, 2);
		solverbh(sta, stb, stacks, 3);	
	}
}

void	argc_check(int argc, t_block *sta, t_block *stb, t_stacks stacks)
{
	if (argc == 1)
		oneargc(sta, stb);
	if (argc == 6)
		fivesolve(sta, stb, stacks);
}