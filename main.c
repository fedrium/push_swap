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
#include <unistd.h>
#include <stdio.h>
int	converter(t_block *sta, int argc, char **argv, t_stacks *stacks)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i]) 
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 1)
				return (1);
			j++;
		}
		sta[i - 1].parti = ft_atoi(argv[i]);
		sta[i - 1].n = 0;
		i++;
	}
	stacks->anum = i;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stacks stacks;
	t_block *sta;
	t_block *stb;
	int i;
	i = 0;
	sta = malloc(sizeof(t_block) * argc);
	stb = malloc(sizeof(t_block) * argc);
	stacks.anum = argc - 1;
	stacks.bnum = 0;
	if (converter(sta, argc, argv, &stacks) || 
		order_check(sta, argc) == 1)
	{
		write(1, "Error, Gay in Progress!\n", 24);
		return (1);
	}
	median_finder(sta, stacks);
	// while (i < argc)
	// {
	// 	printf("sta: %i   ", sta[i].parti);
	// 	// printf("n: %i   \n", sta[i].n);
	// 	printf("stb: %i \n", stb[i].parti);
	// 	i++;
	// }
	// printf("next\n");
	// pa(&stacks);
	// i = 0;
	// while (i < argc)
	// {
	// 	printf("sta: %i   ", stacks.sta[i]);
	// 	printf("stb: %i\n", stacks.stb[i]);
	// 	i++;
	// }
	// i = 0;
	// printf("next\n"); 
	// pa(&stacks);
	// while (i < argc)
	// {
	// 	printf("sta: %i   ", stacks.sta[i]);
	// 	printf("stb: %i\n", stacks.stb[i]);
	// 	i++;
	// }
	// printf("sta: %i\n", stacks.sta[0]);
	return (0);
}