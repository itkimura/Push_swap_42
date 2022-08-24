/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/23 11:03:24 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
 *
*/

int	dublicate_check(int tmp, t_dlst **curr)
{
	t_dlst	*start;

	start = *curr;
	while (*curr)
	{
		if (tmp == (*curr)->value)
		{
			printf("Duplication\n");
			return (0);
		}
		*curr = (*curr)->prev;
	}
	*curr = start;
	return (1);
}

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

void	free_stack(t_dlst **stack)
{
	int		i;
	t_dlst	*tmp;
	t_dlst	*next;

	i = 0;
	next = *stack;
	tmp = *stack;
	while (next)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
		i++;
	}
	*stack = tmp;
	*stack = NULL;
}

int	add_stack(char *str, t_dlst **curr, int *total)
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
	(*total)++;
	return (1);
}

int	init_stack(int ac, char **av, t_dlst **stack_a, int *total)
{
	int		i;
	t_dlst	*curr;

	i = 1;
	*stack_a = dlstnew(NULL, 0);
	if (!*stack_a)
		return (error());
	curr = *stack_a;
	while (i < ac)
	{
		if (!is_valid_str(av[i], &curr, total))
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
