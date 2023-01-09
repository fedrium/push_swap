/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bocal <bocal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:54:07 by bocal             #+#    #+#             */
/*   Updated: 2023/01/07 17:23:01 by bocal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	order_check(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->anum)
	{
		if (stacks->sta[i] > stacks->sta[i + 1])
			return (0);
		i++;
	}
	return (1);
}