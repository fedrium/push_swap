#include "push_swap.h"
#include <stdio.h>

int solver(t_block *sta, t_block *stb, t_stacks stacks)
{
    int	i;
    int	median;

	median = median_finder(sta, stacks);
    i = stacks.anum;
    while (stacks.anum > 3)
	{
        // printf("mid: %i\n", median);
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
	}
	// if (stacks.anum == 2)
	// 	twospin(sta, stacks);
    // if (stb != 0)
    //     solver(sta, stb, stacks);
    return (i);
}

void    twospin(t_block *sta, t_stacks stacks)
{
    if (sta[0].parti > sta[1].parti)
        sa(sta);
}