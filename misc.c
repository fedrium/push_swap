/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <bocal@student.42.fr>                +#+  +:+       +#+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:25:50 by bocal             #+#    #+#             */
/*   Updated: 2022/12/17 16:25:51 by bocal            ###   ########.fr       */
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

int	ft_atoi(char *str)
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
	if (nbr > 2147483647 || nbr < -2147483648)
		return (1);
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

int	median_finder_a(t_block *sta, t_stacks stacks, int pushed)
{
	int	i;
	int	j;
	int	*temp;
	int	temptwo;

	i = 0;
	temp = malloc(sizeof(int) * pushed);
	while (i < pushed)
	{
		temp[i] = sta[i].parti;
		i++;
	}
	i = 0;
	while (i < pushed)
	{
		j = 0;
		while (j + 1 < pushed)
		{
			if (temp[j] > temp[j + 1])
			{
				temptwo = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = temptwo;
			}
			j++;
		}
		i++;
	}
	temptwo = temp[pushed / 2];
	free(temp);
	return (temptwo);
}

int	median_finder_b(t_block *stb, t_stacks stacks, int pushed)
{
	int	i;
	int	j;
	int	*temp;
	int	temptwo;

	i = 0;
	temp = malloc(sizeof(int) * pushed);
	while (i < pushed)
	{
		temp[i] = stb[i].parti;
		i++;
	}
	i = 0;
	while (i < pushed)
	{
		j = 0;
		while (j + 1 < pushed)
		{
			if (temp[j] > temp[j + 1])
			{
				temptwo = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = temptwo;
			}
			j++;
		}
		i++;
	}
	temptwo = temp[pushed /2];
	free(temp);
	return (temptwo);
}
