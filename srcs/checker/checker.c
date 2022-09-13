/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/12 12:22:48 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	activate_display(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-v"))
			return (1);
		i++;
	}
	return (0);
}

int	checker(t_dlst *stack_a, t_dlst *stack_b, int v)
{
	char	*input;
	int		index;

	input = NULL;
	if (is_sorted(stack_a, stack_b))
		return (1);
	if (v)
		visualizer(stack_a, stack_b, input);
	while (get_next_line(0, &input))
	{
		index = get_index(input);
		if (index > rrr)
		{
			error();
			return (0);
		}
		else
			apply_op(index, stack_a, stack_b);
		if (v)
			visualizer(stack_a, stack_b, input);
		free(input);
	}
	return (1);
}
int	init_ans(t_sort **t)
{
	t_sort	*new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		return (0);
	new->max = SORTLIMIT;
	new->total = 0;
	new->prev = -1;
	new->turn = 0;
	new->a_next = 0;
	new->b_next = 0;
	new->b_pivot = 0;
	ft_memset(new->tmp, -1, sizeof(new->tmp));
	ft_memset(new->ans, -1, sizeof(new->ans));
	ft_memset(new->q_ans, -1, sizeof(new->ans));
	*t = new;
	return (1);
}

int	main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	int		total;
		t_sort	*t;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		total = 0;
		if (!init_dlst(&stack_a, &stack_b))
			return (1);
		if (!init_stack(ac, av, &stack_a, &total))
			return (1);
		if (!checker(stack_a, stack_b, activate_display(ac, av)))
			return (1);
		if (!is_sorted(stack_a, stack_b))
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
		if (!init_ans(&t))
			return (0);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	//system("leaks checker");
	return (0);
}
