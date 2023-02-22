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
	while (i < stacks->anum - 1)
	{
		sta[i].parti = sta[i + 1].parti;
		i++;
	}
	sta[i - 1].parti = temp;
}

void	rb(t_block *stb, t_stacks *stacks)
{
	int	temp;
	int	i;

	i = 0;
	temp = stb[0].parti;
	while (i < stacks->bnum - 1)
	{
		stb[i].parti = stb[i + 1].parti;
		i++;
	}
	stb[i - 1].parti = temp;
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

	i = stacks->anum - 2;
	temp = sta[i].parti;
	while (i > 0)
	{
		sta[i].parti = sta[i - 1].parti;
		i--;
	}
	sta[i].parti = temp;
}

void	rrb(t_block *stb, t_stacks *stacks)
{
	int	i;
	int	temp;

	i = stacks->bnum - 2;
	temp = stb[i].parti;
	while (i > 0)
	{
		stb[i].parti = stb[i - 1].parti;
		i--;
	}
	stb[i].parti = temp;
}