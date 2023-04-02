/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:31:44 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 18:00:45 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solverah(t_block *sta, t_stacks stacks, int pushed)
{
	if (pushed == 3)
		three_spin_a(sta, stacks);
	if (pushed == 2)
	{
		if (sta[0].parti > sta[1].parti)
			sa(sta);
	}
}

void	solverbh(t_block *sta, t_block *stb, t_stacks stacks, int pushed)
{
	if (pushed == 3)
		three_spin(sta, stb, stacks);
	if (pushed == 2)
	{
		if (stb[0].parti < stb[1].parti)
			sb(stb);
		pa(sta, stb, &stacks);
		pa(sta, stb, &stacks);
	}
}

void	rotator_a(t_block *sta, int rotated, t_stacks stacks)
{
	int	i;

	i = 0;
	while (i < rotated)
	{
		rra(sta, &stacks);
		i++;
	}
}

void	rotator_b(t_block *stb, int rotated, t_stacks stacks)
{
	int	i;

	i = 0;
	while (i < rotated)
	{
		rrb(stb, &stacks);
		i++;
	}
}
