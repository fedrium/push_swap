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
	return (0);
}

void	error(t_block *sta, t_block *stb)
{
	free(sta);
	free(stb);
	write(2, "Error\n", 6);
	exit(0);
}

void	oneargc(t_block *sta, t_block *stb)
{
	free(sta);
	free(stb);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_block		*sta;
	t_block		*stb;
	int			pushed;

	sta = malloc(sizeof(t_block) * argc);
	stb = malloc(sizeof(t_block) * argc);
	stacks.anum = argc - 1;
	stacks.bnum = 0;
	if (argc == 2)
		twoargc(argv[1], sta, stb, stacks);
	else
	{
		if (symbol_check(argc, argv) == 1
			|| converter(sta, argc, argv, &stacks) == 1
			|| dupe_check(sta, stacks) == 1)
				error(sta, stb);
	}
	pushed = stacks.anum;
	if (argc == 1)
		oneargc(sta, stb);
	solver_sta(sta, stb, pushed, stacks);
	free(sta);
	free(stb);
	return (0);
}

int	spliter(t_block *sta, char *str, t_stacks *stacks)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("working");
	array = ft_split(str, ' ');
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
	free(array);
	stacks->anum = i;
	return (0);
}
