#include "push_swap.h"

void	three_spin(t_block *sta, t_block *stb, t_stacks stacks)
{
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
	else if (stb[0].parti > stb[1].parti && stb[0].parti < stb[2].parti)
	{
		pa(sta, stb, &stacks);
		sb(stb);
		pa(sta, stb, &stacks);
		sa(sta);
		pa(sta, stb, &stacks);
	}
}

void	solverah(t_block *sta, t_stacks stacks, int pushed)
{
	if (pushed == 3)
		three_spin_a(sta, stacks);
	if (pushed == 2)
		twospin(sta, stacks);
}

void	solverbh(t_block *sta, t_block *stb, t_stacks stacks, int pushed)
{
	if (pushed == 3)
		three_spin(sta, stb, stacks);
	if (pushed == 2)
	{
		if (stb[0].parti < stb[1].parti)
			sb(stb);
		pa(sta, stb, &stacks);
		pa(sta, stb, &stacks);
	}
}

void	solver_sta(t_block *sta, t_block *stb, int pushed, t_stacks stacks)
{
	int	i;
	int	median;
	int	rotated;

	median = median_finder_a(sta, stacks, pushed);
	rotated = 0;
	i = pushed;
	if (pushed <= 3)
		solverah(sta, stacks, pushed);
	if (pushed > 3)
	{
		while (i-- > 0)
		{
			if (sta[0].parti < median)
				pb(sta, stb, &stacks);
			else
			{
				ra(sta, &stacks);
				rotated++;
			}
		}
		rotator_a(sta, rotated, stacks);
		solver_sta(sta, stb, (pushed / 2) + (pushed % 2), stacks);
		solver_stb(sta, stb, (pushed / 2), stacks);
	}
}

void	solver_stb(t_block *sta, t_block *stb, int pushed, t_stacks stacks)
{
	int	i;
	int	median;
	int	rotated;

	median = median_finder_b(stb, stacks, pushed);
	rotated = 0;
	i = pushed;
	if (pushed <= 3)
		solverbh(sta, stb, stacks, pushed);
	if (pushed > 3)
	{
		while (i-- > 0)
		{
			if (stb[0].parti >= median)
				pa(sta, stb, &stacks);
			else
			{
				rb(stb, &stacks);
				rotated++;
			}
		}
		rotator_b(stb, rotated, stacks);
		solver_sta(sta, stb, (pushed / 2) + (pushed % 2), stacks);
		solver_stb(sta, stb, (pushed / 2), stacks);
	}
}

void	twospin(t_block *sta, t_stacks stacks)
{
	if (sta[0].parti > sta[1].parti)
		sa(sta);
}

void	three_spin_a(t_block *sta, t_stacks stacks)
{
	if (sta[0].parti > sta[1].parti)
		sa(sta);
	if (sta[0].parti < sta[1].parti && sta[0].parti > sta[2].parti
		|| sta[0].parti < sta[1].parti && sta[1].parti > sta[2].parti)
	{
		ra(sta, &stacks);
		sa(sta);
		rra(sta, &stacks);
	}
	if (sta[0].parti > sta[1].parti)
		sa(sta);
}

void	rotator_a(t_block *sta, int rotated, t_stacks stacks)
{
	int	i;

	i = 0;
	while (i < rotated)
	{
		rra(sta, &stacks);
		i++;
	}
}

void	rotator_b(t_block *stb, int rotated, t_stacks stacks)
{
	int	i;

	i = 0;
	while (i < rotated)
	{
		rrb(stb, &stacks);
		i++;
	}
}
