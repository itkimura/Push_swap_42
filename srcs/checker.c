/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/01 22:58:56 by itkimura         ###   ########.fr       */
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

/*
** If print_stacks flag is turned on, the stack is printed after every move.
** usleep(200000) -> this is a number of microseconds.
** "\E[H\E[2J" is an escape sequence to clear the screen.
*/

void	v_stack(t_dlst *stack_a, t_dlst *stack_b)
{
	t_dlst	*next_a;
	t_dlst	*next_b;

	next_a = stack_a->next;
	next_b = stack_b->next;
	while (next_a != stack_a || next_b != stack_b)
	{
		if (next_a != stack_a)
			ft_printf("%15d | ", next_a->value);
		else
			ft_printf("%15c | ", ' ');
		if (next_a != stack_a)
			next_a = next_a->next;
		if (next_b != stack_b)
			ft_printf("%-15d\n", next_b->value);
		else if(next_b == stack_b)
			ft_printf("%15c\n", ' ');
		if (next_b != stack_b)
			next_b = next_b->next;
		usleep(200000);
	}
}

void	visualizer(t_dlst *stack_a, t_dlst *stack_b, char *input)
{
	static int count;

	ft_printf("\E[H\E[2J");
	if (!input)
	{
		input = ft_strdup("Start");
		count = 0;
	}
	else
		count++;
	ft_printf("      input [%5s]  count[%5d]\n", input, count);
	ft_printf("---------------------------------\n");
	ft_printf("%15s | %15s\n", "Stack A", "Stack B");
	ft_printf("---------------------------------\n");
	v_stack(stack_a, stack_b);
	ft_printf("---------------------------------\n");
}

int checker(t_dlst *stack_a, t_dlst *stack_b, int v)
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
