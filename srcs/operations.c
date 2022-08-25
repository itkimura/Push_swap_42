/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:08:46 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/25 15:21:23 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_dlst *stack)
{
	int	tmp;

	if (stack->next->next == stack || stack->next == stack)
		return (0);
	tmp = stack->next->value;
	stack->next->value = stack->next->next->value;
	stack->next->next->value = tmp;
	return (1);
}

int	push(t_dlst *pop, t_dlst *push)
{
	t_dlst	*tmp;

	if (pop->next == pop)
		return (0);
	tmp = pop->next;
	pop->next = pop->next->next;
	pop->next->prev = pop;
	tmp->next = push->next;
	tmp->next = push->next;
	push->next = tmp;
	tmp->prev = push;
	tmp->next->prev = tmp;
	return (1);
}

int	rotate(t_dlst *stack)
{
	int		top;
	t_dlst	*tmp;

	if (stack->next->next == stack || stack->next == stack)
		return (0);
	tmp = stack->next;
	top = tmp->value;
	while (tmp != stack)
	{
		tmp->value = tmp->next->value;
		tmp = tmp->next;
	}
	tmp->prev->value = top;
	return (1);
}

int	reverse(t_dlst *stack)
{
	int		last;
	t_dlst	*tmp;

	if (stack->next->next == stack || stack->next == stack)
		return (0);
	tmp = stack->prev;
	last = tmp->value;
	while (tmp != stack)
	{
		tmp->value = tmp->prev->value;
		tmp = tmp->prev;
	}
	tmp->next->value = last;
	return (1);
}
