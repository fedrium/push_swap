/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pusher3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:43:26 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/05 16:48:31 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_block *sta, t_block *stb, t_stacks stacks)
{
	rra(sta, &stacks);
	rrb(stb, &stacks);
}

void	freer(t_block *sta, t_block *stb)
{
	free(sta);
	free(stb);
}

int	checking_bonus(t_block *sta, int argc, t_stacks *stacks, char **argv)
{
	if (symbol_check(argv) == 1
		|| converter_bonus(sta, argc, argv, stacks) == 1
		|| dupe_check(sta, *stacks) == 1)
		return (1);
	stacks->anum = argc - 1;
	return (0);
}
