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
// void	ra(t_stacks *stacks)
// {
// 	int	i;
// 	int	temp;

// 	i = 0;
// 	temp = stacks->sta[0];
// 	while (i < stacks->anum)
// 	{
// 		stacks->sta[i] = stacks->sta[i + 1];
// 		i++;
// 	}
// 	stacks->sta[i - 1] = temp;
// }

// void	rb(t_stacks *stacks)
// {
// 	int	i;
// 	int	temp;

// 	i = 0;
// 	temp = stacks->stb[0];
// 	while (i < stacks->bnum)
// 	{
// 		stacks->stb[i] = stacks->stb[i + 1];
// 		i++;
// 	}
// 	stacks->stb[i - 1] = temp;
// }

// void	rr(t_stacks *stacks)
// {
// 	ra(stacks);
// 	rb(stacks);
// }

// void	rra(t_stacks *stacks)
// {
// 	int	i;
// 	int	temp;

// 	i = stacks->anum - 1;
// 	temp = stacks->sta[i];
// 	while (i > 0)
// 	{
// 		stacks->sta[i] = stacks->sta[i - 1];
// 		i--;
// 	}
// 	stacks->sta[i] = temp;
// }

// void	rrb(t_stacks *stacks)
// {
// 	int	i;
// 	int	temp;

// 	i = stacks->bnum - 1;
// 	temp = stacks->stb[i];
// 	while (i > 0)
// 	{
// 		stacks->stb[i] = stacks->stb[i - 1];
// 		i--;
// 	}
// 	stacks->stb[i] = temp;
// }