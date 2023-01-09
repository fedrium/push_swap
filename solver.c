#include "push_swap.h"

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