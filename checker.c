/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:54:07 by bocal             #+#    #+#             */
/*   Updated: 2023/01/14 16:58:36 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
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

int	solve_check(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->anum)
	{
		if (stacks->sta[i] < stacks->sta[i + 1])
			return (0);
		i++;
	}
	return (1);
}