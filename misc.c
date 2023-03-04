/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <bocal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:25:50 by bocal             #+#    #+#             */
/*   Updated: 2022/12/17 16:25:51 by bocal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (!str)
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	neg;

	i = 0;
	nbr = 0;
	neg = 0;
	while ((str[i] >= 1 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (neg % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57 || c == 45)
		return (0);
	else
		return (1);
}

int	median_finder(t_block *sta, t_stacks stacks)
{
	int	i;

	i = 0;
	int	temp[stacks.anum + 1];
	int	temptwo;
	while (sta[i].parti != '\0' && sta != 0)
	{
		temp[i] = sta[i].parti;
		i++;
	}
	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] > temp[i + 1])
		{
			temptwo = temp[i];
			temp[i] = temp[i + 1];
			temp[i] = temptwo;
		}
		i++;
	}

	if (stacks.anum % 2 == 0)
		return(temp[stacks.anum / 2]);
	else
		return(temp[(stacks.anum / 2) + 1]);
}