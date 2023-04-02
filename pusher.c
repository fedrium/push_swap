/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:00:09 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 15:00:39 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_block *sta)
{
	int	temp;
	int	len;

	temp = sta[0].parti;
	sta[0].parti = sta[1].parti;
	sta[1].parti = temp;
	write(1, "sa\n", 3);
}

void	sb(t_block *stb)
{
	int	temp;
	int	len;

	temp = stb[0].parti;
	stb[0].parti = stb[1].parti;
	stb[1].parti = temp;
	write(1, "sb\n", 3);
}

void	ss(t_block *sta, t_block *stb)
{
	sa(sta);
	sb(stb);
	write(1, "ss\n", 3);
}

void	pa(t_block *sta, t_block *stb, t_stacks *stacks)
{
	int	temp1;
	int	i;

	i = stacks->anum;
	temp1 = stb[0].parti;
	if (stb != 0)
	{	
		while (i > 0)
		{
			sta[i].parti = sta[i - 1].parti;
			i--;
		}
		stacks->anum++;
		i = 0;
		while (i < stacks->bnum)
		{
			stb[i].parti = stb[i + 1].parti;
			i++;
		}
		stacks->bnum--;
		sta[0].parti = temp1;
	}
	write(1, "pa\n", 3);
}

void	pb(t_block *sta, t_block *stb, t_stacks *stacks)
{
	int	temp1;
	int	i;

	i = stacks->bnum;
	temp1 = sta[0].parti;
	if (sta != 0)
	{	
		while (i > 0)
		{
			stb[i].parti = stb[i - 1].parti;
			i--;
		}
		stacks->bnum++;
		i = 0;
		while (i < stacks->anum)
		{
			sta[i].parti = sta[i + 1].parti;
			i++;
		}
		stacks->anum--;
		stb[0].parti = temp1;
	}
	write(1, "pb\n", 3);
}
