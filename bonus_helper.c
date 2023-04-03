/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:41:28 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 15:42:48 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ok(void)
{
	write(1, "OK\n", 3);
	exit(0);
}

void	error(int x)
{
	if (x == 0)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	if (x == 1)
	{
		write(1, "Invalid Oppr\n", 13);
		exit(0);
	}
}

int	swap_push(t_block *sta, t_block *stb, t_stacks *stacks, char *op)
{
	if (!ft_strncmp(op, "sa", 3))
		bsa(sta, *stacks);
	else if (!ft_strncmp(op, "sb", 3))
		bsb(stb, *stacks);
	else if (!ft_strncmp(op, "ss", 3))
		bss(sta, stb, *stacks);
	else if (!ft_strncmp(op, "pa", 3))
		pa(sta, stb, stacks);
	else if (!ft_strncmp(op, "pb", 3))
		pb(sta, stb, stacks);
	else
		return (1);
	return (0);
}

void	getophelper(t_block *sta, t_stacks stacks, char *op)
{
	if (op == 0 || op[0] == '\0')
	{
		if (order_check_bonus(sta, stacks.anum) == 0)
			ok();
		else
			error(0);
	}
}

void	getop(t_block *sta, t_block *stb, t_stacks stacks)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		getophelper(sta, stacks, op);
		if (!ft_strncmp(op, "ra", 3))
			ra(sta, &stacks);
		else if (!ft_strncmp(op, "rb", 3))
			rb(stb, &stacks);
		else if (!ft_strncmp(op, "rr", 3))
			rr(sta, stb, &stacks);
		else if (!ft_strncmp(op, "rra", 4))
			rra(sta, &stacks);
		else if (!ft_strncmp(op, "rrb", 4))
			rrb(stb, &stacks);
		else if (!ft_strncmp(op, "rrr", 4))
			rrr(sta, stb, stacks);
		else if (swap_push(sta, stb, &stacks, op) == 1)
			error (1);
		free(op);
	}
}
