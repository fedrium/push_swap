/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:52:21 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 14:59:40 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_block *sta, t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = sta[0].parti;
	while (i < stacks->anum)
	{
		sta[i].parti = sta[i + 1].parti;
		i++;
	}
	sta[i - 1].parti = temp;
	write(1, "ra\n", 3);
}

void	rb(t_block *stb, t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = stb[0].parti;
	while (i < stacks->bnum)
	{
		stb[i].parti = stb[i + 1].parti;
		i++;
	}
	stb[i - 1].parti = temp;
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
