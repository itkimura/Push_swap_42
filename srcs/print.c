#include "push_swap.h"

int		number_of_digits(int nb)
{
	int digit = 0;
	while (nb)
	{
		nb = nb / 10;
		digit++;
	}
	return (digit);
}

void	print_detail(t_dlst *stack_a, t_dlst *stack_b)
{
	int i;
	t_dlst *next_a;
	t_dlst *next_b;

	i = 0;
	next_a = stack_a;
	next_b = stack_b;
	printf("-- stack_a --\n");
	while (next_a)
	{
		if (next_a)
		{
			printf("No.%5d:%15p\tvalue:%10d\tprev:%15p\tnext:%15p\n", i, next_a,  next_a->value, next_a->prev, next_a->next);
			next_a = next_a->next;
		}
		i++;
		if (next_a == stack_a)
			break ;
	}
	i = 0;
	printf("-- stack_b --\n");
	while (next_b)
	{
		if (next_b)
		{
			printf("No.%5d:%15p\tvalue:%10d\tprev:%15p\tnext:%15p\n", i, next_b,  next_b->value, next_b->prev, next_b->next);
			next_b = next_b->next;
		}
		i++;
		if (next_b == stack_b)
			break ;
	}
	printf("-------------\n");
}
void	print_stack(t_dlst *stack_a, t_dlst *stack_b)
{
	t_dlst *next_a;
	t_dlst *next_b;
	int i;
	int total;
	int max_digits = 0;

	i = 0;
	total = 0;
	next_a = stack_a;
	next_b = stack_b;
	while (next_a)
	{
		next_a = next_a->next;
		if (max_digits < number_of_digits(next_a->value))
				max_digits = number_of_digits(next_a->value);
		total++;
		if (next_a == stack_a)
			break ;
	}
	next_a = stack_a;
	printf("print_stack:\n");
	for (int j = 0; j < max_digits + 2; j++)
		printf("-");
	printf("|");
	for (int j = 0; j < max_digits + 2; j++)
		printf("-");
	printf("\n");
	while (i <= total)
	{
		if (next_a && next_a->value)
		{
			for (int j = 0; j < max_digits + 2 - number_of_digits(next_a->value) ; j++)
				printf(" ");
			printf("%d", next_a->value);
			printf("|");
		}
		else if (i)
		{
			for (int j = 0; j < max_digits + 2; j++)
				printf(" ");
			printf("|");
		}
		if ((next_a->next) && ((next_a != stack_a && i > 0) || i == 0))
				next_a = next_a->next;
		if (next_b != stack_b)
		{
			for (int j = 0; j < max_digits + 2 - number_of_digits(next_b->value) ; j++)
				printf(" ");
			printf("%d\n", next_b->value);
		}
		else if (i)
		{
			for (int j = 0; j < max_digits + 2; j++)
				printf(" ");
			printf("\n");
		}
		if ((next_b->next) && ((next_b != stack_b && i > 0) || i == 0))
				next_b = next_b->next;
		i++;
	}
	for (int j = 0; j < max_digits + 2; j++)
		printf("-");
	printf("|");
	for (int j = 0; j < max_digits + 2; j++)
		printf("-");
	printf("\n");
	for (int j = 0; j < max_digits + 1; j++)
		printf(" ");
	printf("a|");
	for (int j = 0; j < max_digits + 1; j++)
		printf(" ");
	printf("b\n");
}
