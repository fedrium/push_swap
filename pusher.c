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
void	sa(t_stacks *stacks)
{
	char	temp;
	int		len;

	temp = stacks->sta[0];
	stacks->sta[0] = stacks->sta[1];
	stacks->sta[1] = temp;
}

void	sb(t_stacks *stacks)
{
	char	temp;
	int		len;

	temp = stacks->stb[0];
	stacks->stb[0] = stacks->stb[1];
	stacks->stb[1] = temp;
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}


void 	pa(t_stacks *stacks)
{
	int	temp2;
	int	temp1;
	int	i;

	i = stacks->anum;
	temp1 = stacks->stb[0];
	if (stacks->stb != 0)
	{	
		while (i > 0)
		{
			stacks->sta[i] = stacks->sta[i - 1];
			i--;
		}
		stacks->anum++;
		i = 0;
		while (i < stacks->bnum)
		{
			stacks->stb[i] = stacks->stb[i + 1];
			i++;
		}
		stacks->bnum--;
		stacks->sta[0] = temp1;
	}
}

void 	pb(t_stacks *stacks)
{
	int	temp2;
	int	temp1;
	int	i;

	i = stacks->bnum;
	temp1 = stacks->sta[0];
	if (stacks->sta != 0)
	{	
		while (i > 0)
		{
			stacks->stb[i] = stacks->stb[i - 1];
			i--;
		}
		stacks->bnum++;
		i = 0;
		while (i < stacks->anum)
		{
			stacks->sta[i] = stacks->sta[i + 1];
			i++;
		}
		stacks->anum--;
		stacks->stb[0] = temp1;
	}
}