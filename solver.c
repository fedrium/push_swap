#include "push_swap.h"
#include <stdio.h>
void	three_swap_a(t_stacks *s)
{
	if (s->sta[0] > s->sta[1] &&
		s->sta[1] < s->sta[2] && s->sta[0] > s->sta[2])
		ra(s);
	else if (s->sta[0] > s->sta[1] && s->sta[1] > s->sta[2])
	{
		ra(s);
		sa(s);
	}
	else if (s->sta[0] > s->sta[1] &&
		s->sta[1] < s->sta[2] && s->sta[0] < s->sta[2])
		sa(s);
	else if (s->sta[0] < s->sta[1] && s->sta[0] < s->sta[2])
	{
		sa(s);
		ra(s);
	}
	else if (s->sta[0] < s->sta[1] && s->sta[0] > s->sta[2])
		rra(s);
}

void	median_finder_a(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->median = 0;
	while (i < stacks->anum)
	{
		stacks->median = stacks->median + stacks->sta[i];
		i++;
	}
	stacks->median = stacks->median/stacks->anum;
}

void	seperator_a(t_stacks *stacks)
{
	int	i;

	i = 0;
	median_finder_a(stacks);
	while (stacks->anum >= 3 && i < stacks->anum)
	{
		if (stacks->sta[0] > stacks->median)
			ra(stacks);
		else
			pb(stacks);
		i++;
	}
	if (stacks->anum >= 3)
		seperator_a(stacks);
	if (stacks->anum <= 2)
	{
		if (stacks->sta[0] > stacks->sta[1])
			sa(stacks);
	}
}

