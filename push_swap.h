/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:21:30 by bocal             #+#    #+#             */
/*   Updated: 2023/01/14 16:48:14 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stacks {
	int *sta;
	int *stb;
	int anum;
	int bnum;
	int	median;
}				t_stacks;

typedef struct s_block {
	int	n;
	int parti;
}				t_block;

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	sa(t_block *sta);
void	sb(t_block *stb);
void	ss(t_block *sta, t_block *stb);
void 	pb(t_block *sta, t_block *stb, t_stacks *stacks);
void 	pa(t_block *sta, t_block *stb, t_stacks *stacks);
void	ra(t_block *sta, t_stacks *stacks);
void	rb(t_block *stb, t_stacks *stacks);
void	rr(t_block *sta, t_block *stb, t_stacks *stacks);
void	rra(t_block *sta, t_stacks *stacks);
void	rrb(t_block *stb, t_stacks *stacks);
int		ft_isdigit(int c);
int		order_check(t_block *sta, int argc);
int	solve_check(t_stacks *stacks, t_block *sta);
void	three_swap_a(t_stacks *stacks);
void	seperator_a(t_stacks *stacks);
int	median_finder_a(t_block *sta, t_stacks stacks, int pushed);
int solver_sta(t_block *sta, t_block *stb, int pushed, t_stacks stacks);
void	twospin(t_block *sta, t_stacks stacks);
void	solver_stb(t_block *sta, t_block *stb, int pushed, t_stacks stacks);
void	three_spin(t_block* sta, t_block *stb, t_stacks stacks);
int	median_finder_b(t_block *stb, t_stacks stacks, int pushed);
void	three_spin_a(t_block *sta, t_stacks stacks);
void	rotator_a(t_block *sta, int rotated, t_stacks stacks);
void	rotator_b(t_block *stb, int rotated, t_stacks stacks);

#endif