#include "push_swap.h"

int	swap(t_dlst *stack)
{
	int	tmp;

	ft_putstr("sa\n");
	if (stack->next->next == stack || stack->next == NULL)
		return (0);
	tmp = stack->next->value;
	stack->next->value = stack->next->next->value;
	stack->next->next->value = tmp;
	return (1);
}

int	push(t_dlst *a, t_dlst *b)
{
	t_dlst *tmp;

	ft_putstr("pb\n");
	if (b->next == NULL)
		return (0);
	tmp = b->next;
	b->next = b->next->next;
	b->next->prev = b;
	tmp->next = a->next;
	a->next = tmp;
	tmp->prev = a;
	return (1);
}

