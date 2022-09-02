/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/02 18:11:03 by itkimura         ###   ########.fr       */
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
	new->prev = -1;
	ft_memset(new->tmp, -1, sizeof(new->tmp));
	ft_memset(new->ans, -1, sizeof(new->ans));
	*t = new;
	return (1);
}

void	free_all(t_dlst **stack_a, t_dlst **stack_b, t_sort *t)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free(t);
}

/*
 * init_dlst -> malloc stacks
 * init_stack -> validation & initialise stack
 * init_ans -> malloc sorting struct
 * 
*/

int	push_swap(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	t_sort	*t;
	int		total;
	int		turn;

	stack_a = NULL;
	stack_b = NULL;
	t = NULL;
	total = 0;
	turn = 0;
	if (!init_dlst(&stack_a, &stack_b))
		return (0);
	if (!init_stack(ac, av, &stack_a, &total))
		return (0);
	if (!init_ans(&t))
		return (0);
	dfs(stack_a, stack_b, t, turn);
	print_ans(t);
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
//	system("leaks push_swap");
	return (0);
}
