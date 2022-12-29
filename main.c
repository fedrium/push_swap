/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bocal <bocal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:33:01 by bocal             #+#    #+#             */
/*   Updated: 2022/12/27 17:29:29 by bocal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
void	converter(int *sta, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		sta[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks stacks;

	stacks.sta = malloc(sizeof(int) * argc);
	stacks.stb = malloc(sizeof(int) * argc);
	converter(stacks.sta, argc, argv);
	pb(stacks.sta, stacks.stb, argc);
	printf("stb: %i", stacks.stb[0]);
	printf("sta: %i", stacks.sta[0]);
	return (0);
}