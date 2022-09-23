/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/23 14:04:19 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_ans(t_sort **t)
{
	t_sort	*new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		return (0);
	new->total = 0;
	new->max = SORTLIMIT;
	new->prev = -1;
	new->turn = 0;
	new->a_next = 0;
	new->b_next = 0;
	new->turn = 0;
	new->q_last = NULL;
	ft_memset(new->tmp, -1, sizeof(new->tmp));
	ft_memset(new->ans, -1, sizeof(new->ans));
	ft_memset(new->next_size, 0, sizeof(new->ans));
	*t = new;
	return (1);
}

/* free all struct in the end */

int	free_all(t_dlst **stack_a, t_dlst **stack_b, t_sort *t)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (t)
		free(t);
	return (0);
}

/* check if the number of argument is less than 7 or not */

int	sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn)
{
	if (!is_sorted(stack_a, stack_b))
	{
		if (t->total < 7)
		{
			dfs(stack_a, stack_b, t, turn);
			print_ans(t);
		}
		else if (!big_sort(stack_a, stack_b, t))
			return (0);
	}
	return (1);
}

/*
 * init_dlst -> malloc stacks
 * init_stack -> validation & initialise stack
 * init_ans -> malloc sorting struct
*/

int	push_swap(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	t_sort	*t;
	int		turn;

	stack_a = NULL;
	stack_b = NULL;
	t = NULL;
	turn = 0;
	if (!init_dlst(&stack_a, &stack_b))
		return (free_all(&stack_a, &stack_b, t));
	if (!init_ans(&t))
		return (free_all(&stack_a, &stack_b, t));
	if (!init_stack(ac, av, &stack_a, &t->total))
		return (free_all(&stack_a, &stack_b, t));
	if (!sort(stack_a, stack_b, t, turn))
		return (free_all(&stack_a, &stack_b, t));
	free_all(&stack_a, &stack_b, t);
	return (1);
}

/*
 * Inside of main function:
 * return (0) = successfully
 * return (1) = Error
*/

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!push_swap(ac, av))
			return (1);
	}
	return (0);
}
