/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <bocal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:09:35 by bocal             #+#    #+#             */
/*   Updated: 2022/12/17 16:09:36 by bocal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	sa(t_block *sta)
{
	char	temp;
	int		len;

	temp = sta[0].parti;
	sta[0].parti = sta[1].parti;
	sta[1].parti = temp;
}

void	sb(t_block *stb)
{
	char	temp;
	int		len;

	temp = stb[0].parti;
	stb[0].parti = stb[1].parti;
	stb[1].parti = temp;
}

void	ss(t_block *sta, t_block *stb)
{
	sa(sta);
	sb(stb);
}


void 	pa(t_block *sta, t_block *stb, t_stacks *stacks)
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
}

void 	pb(t_block *sta, t_block *stb, t_stacks *stacks)
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
}