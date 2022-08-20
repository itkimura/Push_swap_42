#include "push_swap.h"

void	print_stack(t_dlst *stack_a, t_dlst *stack_b, int total)
{
	int i;
	t_dlst *next_a;
	t_dlst *next_b;

	i = 0;
	next_a = stack_a;
	next_b = stack_b;

	printf("print_stack:\n");
	printf("total:%d\n", total);
	printf("-----|-----\n");
	while (i < total)
	{
		if (next_a && next_a->value)
		{
			printf("%4d", next_a->value);
			next_a = next_a->next;
		}
		else
			printf("    ");
		printf(" | ");
		if (next_b && next_b->value)
		{
			printf(" %4d\t", next_b->value);
			next_b = next_b->next;
		}
		else
			printf("    \n");
		i++;
	}
	printf("-----|-----\n");
	printf("   a      b\n");
}
