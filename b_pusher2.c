/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pusher2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:43:34 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 15:43:46 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_block *sta, t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	if (stacks->anum > 1)
	{
		temp = sta[0].parti;
		while (i < stacks->anum)
		{
			sta[i].parti = sta[i + 1].parti;
			i++;
		}
		sta[i - 1].parti = temp;
	}
}

void	rb(t_block *stb, t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	if (stacks->bnum > 1)
	{
		temp = stb[0].parti;
		while (i < stacks->bnum)
		{
			stb[i].parti = stb[i + 1].parti;
			i++;
		}
		stb[i - 1].parti = temp;
	}
}

void	rr(t_block *sta, t_block *stb, t_stacks *stacks)
{
	ra(sta, stacks);
	rb(stb, stacks);
}

void	rra(t_block *sta, t_stacks *stacks)
{
	int	i;
	int	temp;

	i = stacks->anum;
	if (stacks->anum > 1)
	{
		temp = sta[i - 1].parti;
		while (i > 0)
		{
			sta[i].parti = sta[i - 1].parti;
			i--;
		}
		sta[stacks->anum].parti = 0;
		sta[0].parti = temp;
	}
}

void	rrb(t_block *stb, t_stacks *stacks)
{
	int	i;
	int	temp;

	i = stacks->bnum;
	if (stacks->bnum > 1)
	{
		temp = stb[i - 1].parti;
		while (i > 0)
		{
			stb[i].parti = stb[i - 1].parti;
			i--;
		}
		stb[stacks->bnum].parti = 0;
		stb[0].parti = temp;
	}
}
