/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:23:25 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/05 16:07:40 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_check(t_block *sta, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (sta[i].parti > sta[i + 1].parti)
			return (0);
		i++;
	}
	exit (0);
}

int	solve_check(t_stacks *stacks, t_block *sta)
{
	int	i;

	i = 0;
	while (i < stacks->anum - 1)
	{
		if (sta[i].parti > sta[i + 1].parti)
			return (0);
		i++;
	}
	exit (0);
}

int	dupe_check(t_block *sta, t_stacks stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks.anum)
	{
		j = i + 1;
		while (j < stacks.anum)
		{
			if (sta[i].parti == sta[j].parti)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	symbol_check(char **argv)
{
	int	i;
	int	j;
	int	neg;

	i = 1;
	while (argv[i])
	{
		j = 0;
		neg = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
			{
				neg++;
				if (ft_isdigit(argv[i][j + 1]) == 1)
					return (1);
			}
			j++;
		}
		if (neg > 1)
			return (1);
		i++;
	}
	return (0);
}
