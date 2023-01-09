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
	if (c >= 48 && c <= 57)
		return (0);
	else
		return (1);
}
