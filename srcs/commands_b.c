#include "push_swap.h"

int	sb(t_dlst *a)
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

int	pb(t_dlst *a, t_dlst *b)
{
	t_dlst *top_a;
	t_dlst *top_b;
	t_dlst *tmp;

	ft_putstr("pb\n");
	if (a->next == NULL)
		return (0);
	top_a = a->next->next;
	top_b = b->next;
	tmp = a->next;
	a->next = top_a;
	top_a->prev = a;
	b->next = tmp;
	if (top_b == NULL)
		tmp->next = b;
	else
		tmp->next = top_b;
	tmp->prev = b;
	return (1);
}

