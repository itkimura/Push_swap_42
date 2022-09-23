/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:32:31 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/23 11:25:45 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** If print_stacks flag is turned on, the stack is printed after every move.
** usleep(200000) -> this is a number of microseconds.
** "\E[H\E[2J" is an escape sequence to clear the screen.
*/

void	v_stack(t_dlst *stack_a, t_dlst *stack_b)
{
	t_dlst	*next_a;
	t_dlst	*next_b;

	next_a = stack_a->next;
	next_b = stack_b->next;
	while (next_a != stack_a || next_b != stack_b)
	{
		if (next_a != stack_a)
			ft_printf("%15d | ", next_a->value);
		else
			ft_printf("%15c | ", ' ');
		if (next_a != stack_a)
			next_a = next_a->next;
		if (next_b != stack_b)
			ft_printf("%-15d\n", next_b->value);
		else if (next_b == stack_b)
			ft_printf("%15c\n", ' ');
		if (next_b != stack_b)
			next_b = next_b->next;
		if (next_a == stack_a)
			ft_printf("---------------------------------\n");
		usleep(50000);
	}
}

void	visualizer(t_dlst *stack_a, t_dlst *stack_b, char *input)
{
	static int	count;

	ft_printf("\E[H\E[2J");
	if (!input)
	{
		ft_printf("      input [%5s]  count[%5d]\n", input, count);
		count = 0;
	}
	else
	{
		ft_printf("      input [%5s]  count[%5d]\n", input, count);
		count++;
	}
	ft_printf("---------------------------------\n");
	ft_printf("%15s | %-15s\n", "Stack A", "Stack B");
	ft_printf("---------------------------------\n");
	v_stack(stack_a, stack_b);
}
