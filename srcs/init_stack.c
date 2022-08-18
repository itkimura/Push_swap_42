/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/18 17:06:02 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
 *
*/

t_dlst	*dlstnew(t_dlst *prev, int *number)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (!new)
		return (0);
	new->value = number;
	new->prev = prev;
	new->next = NULL;
	return (new);
}

void	free_stack(t_dlst **stack)
{
	int i;
	t_dlst *tmp;
	t_dlst *next;

	i = 0;
	next = *stack;
	tmp = *stack;
	while (next)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	*stack = tmp;
	*stack = NULL;
}

int	init_stack(t_dlst **stack_a, t_dlst **stack_b, int *numbers, int total)
{
	int		i;
	t_dlst	*tmp;
	t_dlst	*next;

	i = 0;
	*stack_a = dlstnew(NULL, &numbers[i++]);
	*stack_b = dlstnew(NULL, 0);
	if (!*stack_a || !*stack_b)
		return (error());
	next = *stack_a;
	while (i < total)
	{
		tmp = dlstnew(next, &numbers[i]);
		next->next = tmp;
		next = next->next;
		i++;
	}
	return (1);
}
