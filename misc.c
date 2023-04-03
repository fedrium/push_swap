/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:25:50 by bocal             #+#    #+#             */
/*   Updated: 2023/04/02 17:19:04 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (!str)
		i++;
	return (i);
}

long	ft_atoi(char *str)
{
	int		i;
	long	nbr;
	int		neg;

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
	if ((c >= 48 && c <= 57) || c == 45)
		return (0);
	else
		return (1);
}

int	median_finder_a(t_block *sta, int pushed)
{
	int	i;
	int	*temp;
	int	temptwo;

	i = 0;
	temptwo = 0;
	temp = malloc(sizeof(int) * pushed);
	while (i < pushed)
	{
		temp[i] = sta[i].parti;
		i++;
	}
	i = 0;
	median_helper(temp, temptwo, pushed);
	temptwo = temp[pushed / 2];
	free(temp);
	return (temptwo);
}

int	median_finder_b(t_block *stb, int pushed)
{
	int	i;
	int	*temp;
	int	temptwo;

	i = 0;
	temptwo = 0;
	temp = malloc(sizeof(int) * pushed);
	while (i < pushed)
	{
		temp[i] = stb[i].parti;
		i++;
	}
	i = 0;
	median_helper(temp, temptwo, pushed);
	temptwo = temp[pushed / 2];
	free(temp);
	return (temptwo);
}
