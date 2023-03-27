/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bocal <bocal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:52:45 by bocal             #+#    #+#             */
/*   Updated: 2023/01/07 16:43:58 by bocal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ra(t_block *sta, t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = sta[0].parti;
	if (stacks->anum > 2)
	{
		while (i < stacks->anum)
		{
			sta[i].parti = sta[i + 1].parti;
			i++;
		}
		sta[i - 1].parti = temp;
	}
	write(1, "ra\n", 3);
}

void	rb(t_block *stb, t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = stb[0].parti;
	if (stacks->bnum > 2)
	{
		while (i < stacks->bnum)
		{
			stb[i].parti = stb[i + 1].parti;
			i++;
		}
		stb[i - 1].parti = temp;
	}
	write(1, "rb\n", 3);
}

void	rr(t_block *sta, t_block *stb, t_stacks *stacks)
{
	ra(sta, stacks);
	rb(stb, stacks);
	write(1, "rrr\n", 4);
}

void	rra(t_block *sta, t_stacks *stacks)
{
	int	i;
	int	temp;

	i = stacks->anum;
	if (stacks->anum < 2)
		exit(0);
	temp = sta[i - 1].parti;
	while (i > 0)
	{
		sta[i].parti = sta[i - 1].parti;
		i--;
	}
	sta[stacks->anum].parti = 0;
	sta[0].parti = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_block *stb, t_stacks *stacks)
{
	int	i;
	int	temp;

	i = stacks->bnum;
	if (stacks->bnum < 2)
		exit(0);
	temp = stb[i - 1].parti;
	while (i > 0)
	{
		stb[i].parti = stb[i - 1].parti;
		i--;
	}
	stb[stacks->bnum].parti = 0;
	stb[0].parti = temp;
	write(1, "rrb\n", 4);
}