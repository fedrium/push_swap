/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:33:01 by bocal             #+#    #+#             */
/*   Updated: 2023/01/14 16:48:30 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	converter(t_block *sta, int argc, char **argv, t_stacks *stacks)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 1)
				return (1);
			j++;
		}
		if (sta[i - 1].parti = ft_atoi(argv[i]) == 1)
			return (1);
		sta[i - 1].n = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_block		*sta;
	t_block		*stb;
	int			i;
	int			pushed;

	i = 0;
	sta = malloc(sizeof(t_block) * argc);
	stb = malloc(sizeof(t_block) * argc);
	stacks.anum = argc - 1;
	stacks.bnum = 0;
	pushed = stacks.anum;
	if (converter(sta, argc, argv, &stacks) == 1
		|| dupe_check(sta, stacks) == 1
		|| order_check(sta, argc) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 1)
		return (0);
	solver_sta(sta, stb, pushed, stacks);
	free(sta);
	free(stb);
	return (0);
}
