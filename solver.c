#include "push_swap.h"
#include <stdio.h>

void	three_spin(t_block* sta, t_block *stb, t_stacks stacks)
{
	printf("working");
	if (stb[0].parti < stb[1].parti)
		sb(stb);
	if (stb[0].parti > stb[1].parti && stb[0].parti > stb[2].parti)
	{
		pa(sta, stb, &stacks);
		if (stb[0].parti > stb[1].parti)
				pa(sta, stb, &stacks);
		else
		{
			sb(stb);
			pa(sta, stb, &stacks);
		}
		pa(sta, stb, &stacks);
	}
	if (stb[0].parti > stb[1].parti && stb[0].parti < stb[2].parti)
	{
		pa(sta, stb, &stacks);
		sb(stb);
		pa(sta, stb, &stacks);
		sa(sta);
		pa(sta, stb, &stacks);
	}
}


int solver_sta(t_block *sta, t_block *stb, int pushed, t_stacks stacks)
{
    int	i;
    int	median;

	median = median_finder_a(sta, stacks);
    i = stacks.anum;
	// printf("mid: %i\n", median);
	// printf("anum: %i\n", stacks.anum);
	if (pushed <= 3)
	{
		if (pushed == 3)
			three_spin_a(sta, stacks);
		if (pushed == 2)
			twospin(sta, stacks);
	}
	if (pushed > 3)
	{
		while (i > 0)
		{
			if (sta[0].parti < median)
			{
				pb(sta, stb, &stacks);
				pushed++;
			}
			else
				ra(sta, &stacks);
			i--;
		}
	}
	// printf("pushed: %i\n", pushed);
    return (i);
}

void	solver_stb(t_block *sta, t_block *stb, int pushed, t_stacks stacks)
{
	int	i;
	int	rtd;
	int	median;

		// printf("pushed_b: %i\n", pushed);
	median = median_finder_b(stb, stacks, pushed / 2);
	printf("median: %i\n", median);
	i = pushed;
	rtd = 0;
	while (i > 0)
	{
		printf("Stb: %i\n", stb[0].parti);
		if (stb[0].parti < median)
		{
			printf("Stb: %i\n", stb[0].parti);
			rb(stb, &stacks);
			rtd++;
		}
		i--;
	}
	printf("rtd: %i\n", rtd);
	if (rtd > 4)
		solver_stb(sta, stb, rtd, stacks);
	else if (rtd < 4)
	{
		if (rtd == 3)
			three_spin(sta, stb, stacks);
		if (rtd == 2)
		{
			if (stb[0].parti > stb[1].parti)
				sb(stb);
			pa(sta, stb, &stacks);
			pa(sta, stb, &stacks);
		}
	}
}

void    twospin(t_block *sta, t_stacks stacks)
{
    if (sta[0].parti > sta[1].parti)
        sa(sta);
}

void	three_spin_a(t_block *sta, t_stacks stacks)
{
	if (sta[0].parti > sta[1].parti && sta[0].parti < sta[2].parti)
		sa(sta);
	if (sta[0].parti > sta[1].parti && sta[0].parti > sta[2].parti)
	{
		if (sta[1].parti > sta[2].parti)
			ra(sta, &stacks);
		ra(sta, &stacks);
	}
	if (sta[1].parti > sta[0].parti && sta[1].parti > sta[2].parti)
	{
		rra(sta, &stacks);
		if (sta[0].parti > sta[1].parti)
			sa(sta);
	}
}