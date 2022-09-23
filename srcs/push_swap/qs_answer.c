/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/15 17:57:48 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	new_qsans(t_qsans **a)
{
	t_qsans	*new;

	new = (t_qsans *)malloc(sizeof(t_qsans));
	if (!new)
		return (0);
	new->index = 0;
	new->next = NULL;
	*a = new;
	return (1);
}

void	add_qsans(int op, t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	t_qsans	*new;

	if (!new_qsans(&new))
		exit(0);
	(void)stack_a;
	(void)stack_b;
	apply_op(op, stack_a, stack_b);
	new->index = op;
	new->next = NULL;
	t->q_last->next = new;
	t->q_last = new;
}

void	qsans_condition(t_qsans **a)
{
	if ((((*a)->index == sa && (*a)->next->index == sb)
			|| ((*a)->index == sb && (*a)->next->index == sa))
		&& (*a)->next->next)
	{
		print_operations(ss);
		*a = (*a)->next->next;
	}
	else if ((((*a)->index == ra && (*a)->next->index == rb)
			|| ((*a)->index == rb && (*a)->next->index == ra))
		&& (*a)->next->next)
	{
		print_operations(rr);
		*a = (*a)->next->next;
	}
	else if ((((*a)->index == pa && (*a)->next->index == pb)
			|| ((*a)->index == pb && (*a)->next->index == pa))
		&& (*a)->next->next)
		*a = (*a)->next->next;
	else
	{
		print_operations((*a)->index);
		*a = (*a)->next;
	}
}

void	qsans_print(t_qsans *a)
{
	int	i;

	i = 0;
	a = a->next;
	while (a->next != NULL)
	{
		qsans_condition(&a);
		i++;
	}
	print_operations(a->index);
}

void	free_qsans(t_qsans **a)
{
	t_qsans	*tmp;
	t_qsans	*next;

	next = (*a);
	while (next)
	{
		tmp = next->next;
		free(next);
		next = tmp;
	}
}
