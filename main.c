/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:11:30 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 18:00:58 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	converter(t_block *sta, int argc, char **argv, t_stacks *stacks)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		spliter(sta, argc, argv, stacks);
	else
	{
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
			sta[i - 1].n = 0;
			i++;
		}
	}
	return (0);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
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
	if (symbol_check(argc, argv) == 1
		|| converter(sta, argc, argv, &stacks) == 1
		|| dupe_check(sta, stacks) == 1)
		error();
	pushed = stacks.anum;
	if (argc == 1)
		return (0);
	i = 0;
	solver_sta(sta, stb, pushed, stacks);
	free(sta);
	free(stb);
	return (0);
}

int	spliter(t_block *sta, int argc, char **argv, t_stacks *stacks)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	array = ft_split(argv[1], ' ');
	while (array[i])
	{
		while (array[i][j])
		{
			if (ft_isdigit(array[i][j]) == 1)
				return (1);
			j++;
		}
		sta[i].parti = ft_atoi(array[i]);
		if (sta[i].parti > 2147483647
			|| sta[i].parti < -2147483648)
			return (1);
		i++;
	}
	stacks->anum = i;
	return (0);
}
