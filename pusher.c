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

void	sa(int *sta)
{
	char	temp;
	int		len;

	temp = sta[0];
	sta[0] = sta[1];
	sta[1] = temp;
}

void	sb(int *stb)
{
	char	temp;
	int		len;

	temp = stb[0];
	stb[0] = stb[1];
	stb[1] = temp;
}

void	ss(int *sta, int *stb)
{
	sa(sta);
	sb(stb);
}

void 	pa(int *sta, int *stb, int argc)
{
	int	temp2;
	int	temp1;
	int	i;

	i = 0;
	temp1 = stb[0];
	if (stb[0] != 0)
	{	
		while (i < argc)
		{
			temp2 = sta[i];
			sta[i] = temp1;
			i++;
		}
		i = 0;
		while (i < argc - 1)
		{
			stb[i] = stb[i + 1];
			i++;
		}
	}
}

void 	pb(int *sta, int *stb, int argc)
{
	int	temp2;
	int	temp1;
	int	i;

	i = 0;
	temp1 = sta[0];
	if (sta[0] != 0)
	{	
		while (i < argc)
		{
			temp2 = stb[i];
			stb[i] = temp1;
			i++;
		}
		i = 0;
		while (i < argc - 1)
		{
			sta[i] = sta[i + 1];
			i++;
		}
	}
}