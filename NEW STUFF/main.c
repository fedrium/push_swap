/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bocal <bocal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:33:01 by bocal             #+#    #+#             */
/*   Updated: 2023/01/07 17:13:33 by bocal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
int	converter(int *sta, int argc, char **argv)
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
		sta[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stacks stacks;
	int i;

	i = 0;
	stacks.sta = malloc(sizeof(int) * argc);
	stacks.stb = malloc(sizeof(int) * argc);
	stacks.anum = argc - 1;
	stacks.bnum = 0;
	if (converter(stacks.sta, argc, argv) == 1 ||
		order_check(&stacks) == 1)
	{
		write(1, "Error, Gay in Progress!\n", 24);
		return (1);
	}
	// pb(&stacks);
	// pb(&stacks);
	// rra(&stacks);
	// rra(&stacks);
	while (i < argc)
	{
		printf("sta: %i   ", stacks.sta[i]);
		printf("stb: %i\n", stacks.stb[i]);
		i++;
	}
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