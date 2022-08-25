/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/25 16:19:45 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_dlst *a, t_dlst *b)
{
	t_dlst *tmp;

	tmp = a->next;
	if (b->next != b)
		return (0);
	while (tmp != a)
	{
		if (tmp->value > tmp->next->value && tmp->next != a)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	char	*input;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		if (!init_dlst(&stack_a, &stack_b))
			return (1);
		if (!init_stack(ac, av, &stack_a))
			return (1);
		print_detail(stack_a, stack_b);
		print_stack(stack_a, stack_b);
		while (get_next_line(0, &input))
		{
			if (!ft_strcmp(input, "detail"))
				print_detail(stack_a, stack_b);
			free(input);
			if (!apply_op(input, stack_a, stack_b))
			{
				error();
				return (1);
			}
			print_stack(stack_a, stack_b);
		}
		if(!check_sort(stack_a, stack_b))
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
		system("leaks checker");
	return (0);
}
