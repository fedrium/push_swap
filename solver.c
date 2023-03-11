#include "push_swap.h"
#include <stdio.h>

void	pta(t_block* sta, t_block *stb, int pamount)
{
	if (pamount == 3)
	{
		if (stb[0].parti < stb[1].parti)
			sb(stb, stacks);
		if (stb[0].parti > stb[1].parti && )
	}
}

int solver_sta(t_block *sta, t_block *stb, int pushed)
{
    int	i;
    int	median;

	median = median_finder(sta, stacks);
    i = stacks.anum;
        printf("mid: %i\n", median);
        // printf("anum: %i\n", stacks.anum);
        while (i > 0)
        {
            if (sta[0].parti < median)
                pb(sta, stb, &stacks);
            else
                ra(sta, &stacks);
            i--;
        }
    if (stacks.anum > 3)
		solver(sta, stb, stacks);
	if (stacks.anum == 2)
		twospin(sta, stacks);
    if (stb != 0)
        solver(sta, stb, stacks);
    return (i);
}

void	solver_stb(t_block *sta, t_block *stb, int pushed)
{
	int	i;
	int	rtd;
	int	median;

	median = median_finder(stb, stacks);
	i = pushed;
	rtd = 0;
	while (i > 0)
	{
		if (stb[0].parti < median)
		{
			rb(stb, stacks);
			rtd++;
		}
		i--;
	}
	if (rtd < 4)
		 
}

void    twospin(t_block *sta, t_stacks stacks)
{
    if (sta[0].parti > sta[1].parti)
        sa(sta);
}