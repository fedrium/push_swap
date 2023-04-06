/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:11:30 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/05 18:04:22 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	converter(t_block *sta, char **argv, t_stacks *stacks)
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
		sta[i - 1].parti = ft_atoi(argv[i]);
		if (sta[i - 1].parti > 2147483647
			|| sta[i - 1].parti < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

void	oneargc(t_block *sta, t_block *stb)
{
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_block		*sta;
	t_block		*stb;
	int			i;
	int j;

	if (argc > 2)
	{
		sta = malloc(sizeof(t_block) * argc);
		stb = malloc(sizeof(t_block) * argc);
		if (checking(sta, argc, &stacks, argv))
			error(sta, stb);
	}
	stacks.bnum = 0;
	if (argc == 2)
	{
		i = cnt_word(argv[1], ' ') + 1;
		sta = malloc(sizeof(t_block) * i);
		stb = malloc(sizeof(t_block) * i);
		twoargc(argv[1], sta, stb, &stacks);
	}
	argc_check(argc, sta, stb, stacks);
	freer(sta, stb);
	return (0);
}

void	solvehelper(t_block *sta, t_block *stb, int pushed, t_stacks stacks)
{
	solver_sta(sta, stb, (pushed / 2) + (pushed % 2), stacks);
	solver_stb(sta, stb, (pushed / 2), stacks);
}
