/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/24 17:31:59 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(char *input)
{
	int		i;
	char	**str;


	i = 0;
	str = (char *[]){"sa", "ra", "rra", "sb", "rb", "rrb",
					 "ss", "rr", "rrr", "pa", "pb"};
	while (i < 11)
	{
		if (!ft_strcmp(str[i], input))
			break ;
		i++;
	}
	return (i);
}

int	apply_op(int index, t_dlst *stack_a, t_dlst *stack_b)
{
	if (index == sa)
		return (swap(stack_a));
	if (index == sb)
		return (swap(stack_b));
	return (0);
}

int	check_sort(t_dlst *a, t_dlst *b)
{
	t_dlst *tmp;

	tmp = a->next;
	if (b->next != NULL)
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
	int total;
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	char	*input;

	if (ac >= 2)
	{
		stack_a = dlstnew(NULL, 0);
		stack_b = dlstnew(NULL, 0);
		total = 0;
		if (!stack_a || !stack_b)
			return (1);
		if (!init_stack(ac, av, &stack_a))
			return (1);
		print_detail(stack_a, stack_b);
		print_stack(stack_a, stack_b);
		while (get_next_line(0, &input))
		{
			printf("input = %s\n", input);
			apply_op(get_index(input), stack_a, stack_b);
			print_stack(stack_a, stack_b);
		}
		if(!check_sort(stack_a, stack_b))
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
	}
	return (0);
}
