#include "push_swap.h"

void	bsa(t_block *sta, t_stacks stacks)
{
	int	temp;
	int	len;
	if (stacks.anum > 1)
	{
		temp = sta[0].parti;
		sta[0].parti = sta[1].parti;
		sta[1].parti = temp;
	}
}

void	bsb(t_block *stb, t_stacks stacks)
{
	int	temp;
	int	len;

	if (stacks.bnum > 1)
	{
		temp = stb[0].parti;
		stb[0].parti = stb[1].parti;
		stb[1].parti = temp;
	}
}

void	bss(t_block *sta, t_block *stb, t_stacks stacks)
{
	bsa(sta, stacks);
	bsb(stb, stacks);
}


void 	pa(t_block *sta, t_block *stb, t_stacks *stacks)
{
	int	temp1;
	int	i;

	i = stacks->anum;
	if (stb != 0 && stacks->bnum > 0)
	{	
		temp1 = stb[0].parti;
		while (i > 0)
		{
			sta[i].parti = sta[i - 1].parti;
			i--;
		}
		stacks->anum++;
		i = 0;
		while (i < stacks->bnum)
		{
			stb[i].parti = stb[i + 1].parti;
			i++;
		}
		stacks->bnum--;
		sta[0].parti = temp1;
	}
}

void 	pb(t_block *sta, t_block *stb, t_stacks *stacks)
{
	int	temp1;
	int	i;

	i = stacks->bnum;
	if (sta != 0 && stacks->anum > 0)
	{	
		temp1 = sta[0].parti;
		while (i > 0)
		{
			stb[i].parti = stb[i - 1].parti;
			i--;
		}
		stacks->bnum++;
		i = 0;
		while (i < stacks->anum)
		{
			sta[i].parti = sta[i + 1].parti;
			i++;
		}
		stacks->anum--;
		stb[0].parti = temp1;
	}
}