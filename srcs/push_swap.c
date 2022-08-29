/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/29 17:02:02 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Insid of mail function:
 * return (0) = successfully
 * return (1) = Error
 * 
*/

int	init_ans(t_sort **t)
{
	t_sort *new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		return (0);
	new->max = SORTLIMIT;
	ft_memset(new->tmp, -1, sizeof(new->tmp));
	ft_memset(new->ans, -1, sizeof(new->ans));
	*t = new;
	return (1);
}

void	print_pos(int index)
{
	if (index == sa)
		ft_putstr("sa\n");
}

void print_ans(t_sort *t)
{
	int	i;

	printf("print_ans here!\n");
	i = 0;
	while (i < t->max)
		print_pos(t->ans[i++]);
}

int	main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	t_sort	*t;
	int		total;
	int		turn;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		t = NULL;
		total = 0;
		turn = 0;
		if (!init_dlst(&stack_a, &stack_b))
			return (1);
		if (!init_stack(ac, av, &stack_a, &total))
			return (1);
		if (!init_ans(&t))
			return (1);
		print_detail(stack_a, stack_b);
		print_stack(stack_a, stack_b);
/*
		if (!small_sort(stack_a, stack_b, total))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
*/
		dfs(stack_a, stack_b, t, turn);
		print_ans(t);
		free_stack(&stack_a);
		free_stack(&stack_b);
		free(t);
	}
	system("leaks push_swap");
	return (0);
}
