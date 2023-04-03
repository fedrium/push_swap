/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:31:03 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 18:02:20 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps(t_block *sta, t_block *stb, t_stacks stacks)
{
	for (int i = 0; i < stacks.anum; i++)
	{
		printf("sta: %li stb: %li\n", sta[i].parti, stb[i].parti);
	}
	printf("\n");
}

void	three_spin(t_block *sta, t_block *stb, t_stacks stacks)
{
	if (stb[0].parti < stb[1].parti)
		sb(stb);
	if (stb[0].parti > stb[1].parti && stb[0].parti > stb[2].parti)
	{
		pa(sta, stb, &stacks);
		if (stb[0].parti > stb[1].parti)
			pa(sta, stb, &stacks);
		else
		{
			sb(stb);
			pa(sta, stb, &stacks);
		}
		pa(sta, stb, &stacks);
	}
	else if (stb[0].parti > stb[1].parti && stb[0].parti < stb[2].parti)
	{
		pa(sta, stb, &stacks);
		sb(stb);
		pa(sta, stb, &stacks);
		sa(sta);
		pa(sta, stb, &stacks);
	}
}

void	solver_sta(t_block *sta, t_block *stb, int pushed, t_stacks stacks)
{
	int	i;
	int	median;
	int	rotated;

	median = median_finder_a(sta, pushed);
	rotated = 0;
	i = pushed;
	if (pushed <= 3)
		solverah(sta, stacks, pushed);
	if (pushed > 3)
	{
		while (i > 0)
		{
			if (sta[0].parti < median)
				pb(sta, stb, &stacks);
			else
			{
				ra(sta, &stacks);
				rotated++;
			}
			i--;
		}
		rotator_a(sta, rotated, stacks);
		solver_sta(sta, stb, (pushed / 2) + (pushed % 2), stacks);
		solver_stb(sta, stb, (pushed / 2), stacks);
	}
}

void	solver_stb(t_block *sta, t_block *stb, int pushed, t_stacks stacks)
{
	int	i;
	int	median;
	int	rotated;

	median = median_finder_b(stb, pushed);
	rotated = 0;
	i = pushed;
	if (pushed <= 3)
		solverbh(sta, stb, stacks, pushed);
	if (pushed > 3)
	{
		while (i > 0)
		{
			if (stb[0].parti >= median)
				pa(sta, stb, &stacks);
			else
			{
				rb(stb, &stacks);
				rotated++;
			}
			i--;
		}
		rotator_b(stb, rotated, stacks);
		solver_sta(sta, stb, (pushed / 2) + (pushed % 2), stacks);
		solver_stb(sta, stb, (pushed / 2), stacks);
	}
}

void	twospin(t_block *sta)
{
	if (sta[0].parti > sta[1].parti)
		sa(sta);
}

void	three_spin_a(t_block *sta, t_stacks stacks)
{
	if (sta[0].parti > sta[1].parti)
		sa(sta);
	if ((sta[0].parti < sta[1].parti && sta[0].parti > sta[2].parti)
		|| (sta[0].parti < sta[1].parti && sta[1].parti > sta[2].parti))
	{
		ra(sta, &stacks);
		sa(sta);
		rra(sta, &stacks);
	}
	if (sta[0].parti > sta[1].parti)
		sa(sta);
}
