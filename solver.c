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

	median = median_finder(sta, stacks);
    i = stacks.anum;
        // printf("mid: %i\n", median);
        // printf("anum: %i\n", stacks.anum);
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
    if (stacks.anum > 3)
		solver_sta(sta, stb, pushed, stacks);
	if (stacks.anum <= 3)
		solver_stb(sta, stb, pushed, stacks);
	// if (stacks.anum == 2)
	// 	twospin(sta, stacks);
    // if (stb != 0)
        // solver_sta(sta, stb, pushed, stacks);
	printf("pushed: %i\n", pushed);
    return (i);
}

void	solver_stb(t_block *sta, t_block *stb, int pushed, t_stacks stacks)
{
	int	i;
	int	rtd;
	int	median;

		printf("pushed_b: %i\n", pushed);
	median = median_finder(stb, stacks);
	i = pushed;
	rtd = 0;
	while (i > 0)
	{
		if (stb[0].parti < median)
		{
			rb(stb, &stacks);
			rtd++;
		}
		i--;
	}
	// printf("rtd: %i\n", rtd);
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