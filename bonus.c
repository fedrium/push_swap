/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:23:57 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/02 15:42:23 by cyu-xian         ###   ########.fr       */
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
			j = -1;
			while (argv[i][j++])
			{
				if (ft_isdigit(argv[i][j]) == 1)
					return (1);
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

int	spliter(t_block *sta, int argc, char **argv, t_stacks *stacks)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	(void)argc;
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

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_block		*sta;
	t_block		*stb;

	sta = malloc(sizeof(t_block) * argc);
	stb = malloc(sizeof(t_block) * argc);
	stacks.anum = argc - 1;
	stacks.bnum = 0;
	if (symbol_check(argc, argv) == 1
		|| converter(sta, argc, argv, &stacks) == 1
		|| dupe_check(sta, stacks) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	getop(sta, stb, stacks);
	if (argc == 1)
		return (0);
	free(sta);
	free(stb);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > i && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i] && (s1[i] != '\n' || s2[i] != '\0'))
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}	
	return (0);
}

int	order_check_bonus(t_block *sta, int anum)
{
	int	i;

	i = 0;
	while (i < anum - 1)
	{
		if (sta[i].parti > sta[i + 1].parti)
			return (1);
		i++;
	}
	return (0);
}
