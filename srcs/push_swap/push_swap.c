/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/07 13:54:28 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_ans(t_sort **t)
{
	t_sort	*new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		return (0);
	new->max = SORTLIMIT;
	new->total = 0;
	new->prev = -1;
	new->total_turn = 0;
	new->quick_sort = NULL;
	new->b_size = 0;
	new->a_next_index = 0;
	new->b_next_index = 0;
	ft_memset(new->tmp, -1, sizeof(new->tmp));
	ft_memset(new->ans, -1, sizeof(new->ans));
	*t = new;
	return (1);
}

/* free all struct in the end */

void	free_all(t_dlst **stack_a, t_dlst **stack_b, t_sort *t)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(t);
}


/* check if the number of argument is less than 7 or not */

int	sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn)
{
	if (t->total < 7)
	{
		dfs(stack_a, stack_b, t, turn);
		print_ans(t);
	}
	else if (!big_sort(stack_a, stack_b, t))
		return (0);
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
		return (0);
	if (!init_ans(&t))
		return (0);
	if (!init_stack(ac, av, &stack_a, &t->total))
		return (0);
	if (!sort(stack_a, stack_b, t, turn))
		return (0);
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
	if (ac >= 2)
	{
		if (!push_swap(ac, av))
			return (1);
	}
	system("leaks push_swap");
	return (0);
}
