/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/30 14:07:53 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	char	*input;
	int		total;
	int		index;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		total = 0;
		if (!init_dlst(&stack_a, &stack_b))
			return (1);
		if (!init_stack(ac, av, &stack_a, &total))
			return (1);
//		print_detail(stack_a, stack_b);
//		print_stack(stack_a, stack_b);
		while (get_next_line(0, &input))
		{
			if (!ft_strcmp(input, "detail"))
//				print_detail(stack_a, stack_b);
			free(input);
			index = get_index(input);
			print_operations(index);
			if (index > rrr)
			{
				error();
				return (1);
			}
			else
			{
				apply_op(index, stack_a, stack_b);
			}
//			print_stack(stack_a, stack_b);
		}
		if (!is_sorted(stack_a, stack_b))
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
//	system("leaks checker");
	return (0);
}
