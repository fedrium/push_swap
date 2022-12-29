/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bocal <bocal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:21:30 by bocal             #+#    #+#             */
/*   Updated: 2022/12/27 17:11:06 by bocal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stacks {
	int *sta;
	int *stb;
}				t_stacks;

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	sa(int *sta);
void	sb(int *stb);
void	ss(int *sta, int *stb);
void 	pb(int *sta, int *stb, int argc);
void 	pa(int *sta, int *stb, int argc);

#endif