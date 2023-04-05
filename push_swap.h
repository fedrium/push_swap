/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyu-xian <cyu-xian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:21:30 by cyu-xian          #+#    #+#             */
/*   Updated: 2023/04/05 17:58:19 by cyu-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stacks {
	int	anum;
	int	bnum;
	int	median;
}				t_stacks;

typedef struct s_block {
	long	parti;
}				t_block;

int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		order_check(t_block *sta, int argc);
int		solve_check(t_stacks *stacks, t_block *sta);
int		median_finder_a(t_block *sta, int pushed);
int		median_finder_b(t_block *stb, int pushed);
int		dupe_check(t_block *sta, t_stacks stacks);
int		symbol_check(char **argv);
int		spliter(t_block *sta, char *str, t_stacks *stacks);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		order_check_bonus(t_block *sta, int anum);
int		cnt_word(char const *str, char c);
int		symbol_check_two(char **array);
int		spliter_bonus(t_block *sta, int argc, char **argv, t_stacks *stacks);
int		spliter(t_block *sta, char *str, t_stacks *stacks);
int		converter_bonus(t_block *sta, int argc, char **argv, t_stacks *stacks);
int		converter(t_block *sta, char **argv, t_stacks *stacks);
int		checking_bonus(t_block *sta, int argc, t_stacks *stacks, char **argv);
int		checking(t_block *sta, t_stacks stacks, char **argv);

long	ft_atoi(char *str);

char	**ft_split(char const *s, char c);

void	sa(t_block *sta);
void	sb(t_block *stb);
void	ss(t_block *sta, t_block *stb);
void	pb(t_block *sta, t_block *stb, t_stacks *stacks);
void	pa(t_block *sta, t_block *stb, t_stacks *stacks);
void	ra(t_block *sta, t_stacks *stacks);
void	rb(t_block *stb, t_stacks *stacks);
void	rr(t_block *sta, t_block *stb, t_stacks *stacks);
void	rra(t_block *sta, t_stacks *stacks);
void	rrb(t_block *stb, t_stacks *stacks);
void	three_swap_a(t_stacks *stacks);
void	seperator_a(t_stacks *stacks);
void	solver_sta(t_block *sta, t_block *stb, int pushed, t_stacks stacks);
void	twospin(t_block *sta);
void	solver_stb(t_block *sta, t_block *stb, int pushed, t_stacks stacks);
void	three_spin(t_block *sta, t_block *stb, t_stacks stacks);
void	three_spin_a(t_block *sta, t_stacks stacks);
void	rotator_a(t_block *sta, int rotated, t_stacks stacks);
void	rotator_b(t_block *stb, int rotated, t_stacks stacks);
void	rrr(t_block *sta, t_block *stb, t_stacks stacks);
void	getop(t_block *sta, t_block *stb, t_stacks stacks);
void	bsa(t_block *sta, t_stacks stacks);
void	bsb(t_block *stb, t_stacks stacks);
void	bss(t_block *sta, t_block *stb, t_stacks stacks);
void	solverah(t_block *sta, t_stacks stacks, int pushed);
void	solverbh(t_block *sta, t_block *stb, t_stacks stacks, int pushed);
void	ok(void);
void	median_helper(int *temp, int temptwo, int pushed);
void	ps(t_block *sta, t_block *stb, t_stacks stacks);
void	twoargc(char *str, t_block *sta, t_block *stb, t_stacks *stacks);
void	error(t_block *sta, t_block *stb);
void	error_bonus(int x, t_block *sta, t_block *stb);
void	error(t_block *sta, t_block *stb);
void	freeing(char **array);
void	solvehelper(t_block *sta, t_block *stb, int pushed, t_stacks stacks);
void	freer(t_block *sta, t_block *stb);
void	argc_check(int argc, t_block *sta, t_block *stb, t_stacks stacks);
void	oneargc(t_block *sta, t_block *stb);

#endif