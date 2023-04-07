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

int	checking(t_block *sta, int argc, t_stacks *stacks, char **argv)
{
	stacks->anum = argc - 1;
	if (symbol_check(argv) == 1
		|| converter(sta, argv) == 1
		|| dupe_check(sta, *stacks) == 1)
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

	i = 5;
	median = median_finder_a(sta, 5);
	while (i > 0)
	{
		if (sta[0].parti < median)
			pb(sta, stb, &stacks);
		else
			ra(sta, &stacks);
		i--;
	}
	if (stacks.anum == 3)
	{
		threesolve(sta, stacks);
		solverbh(sta, stb, stacks, 2);
	}
}

void	threesolve(t_block *sta, t_stacks stacks)
{
	if (sta[1].parti > sta[0].parti && sta[1].parti > sta[2].parti)
		rra(sta, &stacks);
	if (sta[0].parti > sta[1].parti)
		sa(sta);
	if (sta[0].parti > sta[1].parti && sta[0].parti < sta[2].parti)
		ra(sta, &stacks);
	if (sta[0].parti > sta[1].parti)
		sa(sta);
}

void	argc_check(int argc, t_block *sta, t_block *stb, t_stacks stacks)
{
	solve_check(&stacks, sta);
	if (argc == 1)
		oneargc();
	else if (argc == 6)
		fivesolve(sta, stb, stacks);
	else if (argc == 4)
		threesolve(sta, stacks);
	else
		solver_sta(sta, stb, stacks.anum, stacks);
}
