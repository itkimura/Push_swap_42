#include "push_swap.h"

int	sa(t_dlst *a)
{
	int	tmp;

	ft_putstr("sa\n");
	if (a->next->next == a || a->next == NULL)
		return (0);
	tmp = a->next->value;
	a->next->value = a->next->next->value;
	a->next->next->value = tmp;
	return (1);
}

int	pa(t_dlst *a, t_dlst *b)
{
	t_dlst *top_a;
	t_dlst *top_b;
	t_dlst *tmp;

	ft_putstr("pb\n");
	if (a->next == )
		return (0);
	tmp = a->next;
	a->next = a->next->next;
	a->next->prev = a;
	tmp->next = b->next;
	b->next = tmp;
	tmp->prev = b;
	return (1);
}

