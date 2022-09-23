/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/15 18:14:57 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
*/
int	stack_size(t_dlst *stack)
{
	int		i;
	t_dlst	*tmp;

	i = 0;
	tmp = stack->next;
	while (tmp != stack)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_b_sorted(t_dlst *b, t_sort *t)
{
	t_dlst	*tmp;

	tmp = b->next;
	while (tmp != b)
	{
		if (tmp->value > tmp->next->value && tmp->next != b)
			return (0);
		tmp = tmp->next;
	}
	if (stack_size(b) != t->b_size)
		return (0);
	return (1);
}

int	is_sorted(t_dlst *a, t_dlst *b)
{
	t_dlst	*tmp;

	tmp = a->next;
	if (b->next != b)
		return (0);
	while (tmp != a)
	{
		if (tmp->value > tmp->next->value && tmp->next != a)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
