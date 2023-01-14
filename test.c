#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack{
	int	n;
	int	part;
	char	stk;
}				t_stack;

int	main(void)
{
	t_stack	*stka;
	t_stack	*stkb;

	stka = malloc(sizeof(t_stack) * 10);
	stkb = malloc(sizeof(t_stack) * 10);
	int i;
	i = 0;
	while(i < 10)
	{
		stka[i].n = i;
		stka[i].part = i + 1;
		i++;
	}

// pa
// {
// 	stkb[i].stk = 'b'
// }
// pb

	for (int i = 0; i < 10; i++)
	{
		printf("n is : %d\n, partition is : %d\n", stka[i].n, stka[i].part);
	}

// 	int *lmao;

// 	while (i < 10)
// 	{
// 		lmao[i] = i;
// 		i++;
// 	}
}