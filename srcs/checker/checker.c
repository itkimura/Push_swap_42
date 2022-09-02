/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/02 18:18:05 by itkimura         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	int		total;

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
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	//system("leaks checker");
	return (0);
}
