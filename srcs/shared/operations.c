/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:08:46 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/15 18:15:40 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_dlst *stack)
{
	t_dlst	*top;

	if (stack->next->next == stack || stack->next == stack)
		return (0);
	top = stack->next;
	stack->next = top->next;
	top->next = stack->next->next;
	stack->next->next = top;
	stack->next->prev = stack;
	top->prev = stack->next;
	top->next->prev = top;
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
	t_dlst	*top;

	if (stack->next->next == stack || stack->next == stack)
		return (0);
	top = stack->next;
	stack->next = top->next;
	stack->next->prev = stack;
	top->prev = stack->prev;
	stack->prev->next = top;
	top->next = stack;
	stack->prev = top;
	return (1);
}

int	reverse(t_dlst *stack)
{
	t_dlst	*last;

	if (stack->next->next == stack || stack->next == stack)
		return (0);
	last = stack->prev;
	last->prev->next = stack;
	stack->prev = last->prev;
	last->next = stack->next;
	stack->next->prev = last;
	stack->next = last;
	last->prev = stack;
	return (1);
}
