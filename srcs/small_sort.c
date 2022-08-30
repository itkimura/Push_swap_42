/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:14:39 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/30 11:04:09 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* small sort
void	sort_2(t_dlst *a, t_dlst *b)
{
	if (*a->next > *a->next->next)

}*/

int	small_sort(t_dlst *a, t_dlst *b, int total)
{
	(void)a;
	(void)b;
	if (total == 1 || !is_sorted(a, b))
		return (0);
//	printf("total = %d\n", total);
	return (0);
}

void	update_ans(t_sort *t, int turn)
{
	int	i;

	t->max = turn;
//	printf("t->max = %d\n", t->max);
	i = 0;
	while (i < turn)
	{
		t->ans[i] = t->tmp[i];
//		printf("t->ans[%d] = %d\n", i, t->ans[i]);
		i++;
	}
}

void	dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn)
{
	int ops;

	ops = -1;
	if (turn >= t->max)
		return ;
	if (is_sorted(stack_a, stack_b))
	{
//		printf("is_sorted: turn = %d\n", turn);
//		print_stack(stack_a, stack_b);
//		for (int i = 0; i < turn ; i++)
//			printf("t->tmp[%d] = %d\n", i, t->tmp[i]);
		return (update_ans(t, turn));
	}
	while (++ops <= rrr) 
	{
//		printf("turn = %d ops = %d\n", turn, ops);
//		printf("-- before --\n");
//		print_stack(stack_a, stack_b);
		if (avoid_check(ops, t) || turn >= t->max)
		{
//			printf("avoid = true || turn >= t->max\n");
			continue ;
		}
		if (!sort_dlst(stack_a, stack_b, ops, false))
			continue ;
//		printf("-- after --\n");
//		print_stack(stack_a, stack_b);
		t->prev = ops;
		t->tmp[turn] = ops;
//		for (int i = 0; t->tmp[i] >= 0 ; i++)
//			printf("t->tmp[%d] = %d\n", i, t->tmp[i]);
		dfs(stack_a, stack_b, t, turn + 1);
		sort_dlst(stack_a, stack_b, ops, true);
//		printf("-- recover --\n");
//		print_stack(stack_a, stack_b);
	}
}
