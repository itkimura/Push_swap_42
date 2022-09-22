/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/22 16:34:21 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_line(t_dlst *stack_a, t_dlst *stack_b, t_checker *c, int v)
{
	int			index;
	t_checker	*tmp;

	tmp = c;
	while (tmp->next)
	{
		index = get_index(tmp->line);
		if (index > rrr)
			return (0);
		else
			apply_op(index, stack_a, stack_b);
		if (v)
			visualizer(stack_a, stack_b, tmp->line);
		tmp = tmp->next;
	}
	return (1);
}

int	read_line(t_checker *c)
{
	int			gnl;
	char		*input;
	t_checker	*tmp;
	t_checker	*new;

	gnl = 1;
	input = NULL;
	tmp = c;
	while (gnl)
	{
		gnl = get_next_line(0, &input);
		if (gnl == -1)
			exit(0);
		if (gnl == 0)
			break ;
		tmp->line = input;
		if (!new_checker(&new))
			exit (0);
		tmp->next = new;
		tmp = tmp->next;
	}
	return (1);
}

int	checker(t_dlst *stack_a, t_dlst *stack_b, int v)
{
	t_checker	*c;

	if (v)
		visualizer(stack_a, stack_b, 0);
	if (!new_checker(&c))
		exit (0);
	if (!read_line(c))
		return (0);
	if (!test_line(stack_a, stack_b, c, v))
	{
		free_checker(c);
		return (0);
	}
	free_checker(c);
	return (1);
}

int	init_checker(int ac, char **av, t_dlst **stack_a, t_dlst **stack_b)
{
	int		total;

	total = 0;
	if (!init_dlst(stack_a, stack_b))
		return (0);
	if (!init_stack(ac, av, stack_a, &total))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		if (!init_checker(ac, av, &stack_a, &stack_b))
			return (free_stacks(&stack_a, &stack_b));
		if (!checker(stack_a, stack_b, activate_display(ac, av)))
			ft_putstr("Error\n");
		else
		{
			if (!is_sorted(stack_a, stack_b))
				ft_putstr("KO\n");
			else
				ft_putstr("OK\n");
		}
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
