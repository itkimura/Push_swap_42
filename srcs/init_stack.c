/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/25 16:22:05 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
 *
*/

t_dlst	*dlstnew(t_dlst *prev, int number)
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

int	init_dlst(t_dlst **stack_a, t_dlst **stack_b)
{
	*stack_a = dlstnew(NULL, 0);
	if (!*stack_a)
		return (0);
	*stack_b = dlstnew(NULL, 0);
	if (!*stack_b)
	{
		free(*stack_a);
		return (0);
	}
	(*stack_b)->next = *stack_b;
	(*stack_b)->prev = *stack_b;
	return (1);
}

void	free_stack(t_dlst **stack)
{
	t_dlst	*tmp;
	t_dlst	*next;

	next = (*stack)->next;
	while (next != *stack)
	{
		tmp = next->next;
		free(next);
		next = tmp;
	}
}

int	add_stack(char *str, t_dlst **curr)
{
	long int	tmp;
	t_dlst		*new;

	tmp = ft_atoli(str);
	if (tmp < INT_MIN || tmp > INT_MAX)
	{
		printf("INT_MIN or INT_MAX\n");
		return (0);
	}
	if (!dublicate_check(tmp, curr))
		return (0);
	new = dlstnew(*curr, (int)tmp);
	if (!new)
		return (0);
	(*curr)->next = new;
	(*curr) = (*curr)->next;
	return (1);
}

int	init_stack(int ac, char **av, t_dlst **stack_a)
{
	int		i;
	t_dlst	*curr;

	i = 1;
	curr = *stack_a;
	while (i < ac)
	{
		if (!is_valid_str(av[i], &curr))
		{
			free_stack(stack_a);
			return (error());
		}
		i++;
	}
	curr->next = *stack_a;
	(*stack_a)->prev = curr;
	return (1);
}
