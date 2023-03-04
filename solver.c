#include "push_swap.h"
#include <stdio.h>

int solver(t_block *sta, t_block *stb, t_stacks stacks)
{
    int	i;
    int	median;

	median = median_finder(sta, stacks);
    i = 0;
    while (solve_check(&stacks, sta) == 0)
	{
        // printf("mid: %i\n", median);
        // printf("anum: %i\n", stacks.anum);
        while (i < stacks.anum)
        {
            if (sta[0].parti < median)
                pb(sta, stb, &stacks);
            else
                ra(sta, &stacks);
            printf("i: %i\n", i);
            i++;
        }
	}
    // twospin(sta, stacks);
    // if (stb != 0)
    //     solver(sta, stb, stacks);
    return (i);
}

void    twospin(t_block *sta, t_stacks stacks)
{
    // printf("anum: %i\n", stacks.anum);
    if (sta[0].parti > sta[1].parti && stacks.anum > 1)
        sa(sta);
}