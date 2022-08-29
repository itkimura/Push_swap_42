/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:14:39 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/29 17:07:12 by itkimura         ###   ########.fr       */
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
	printf("total = %d\n", total);
	return (0);
}

void	update_ans(t_sort *t, int turn)
{
	int	i;

	t->max = turn;
	i = -1;
	while (++i < turn)
	{
		t->ans[i] = t->tmp[i];
		printf("t->tmp[%d] = %d\n", i, t->tmp[i]);
		printf("t->ans[%d] = %d\n", i, t->ans[i]);
	}
}

void	dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn)
{
	int ops;

	ops = 0;
	if (turn >= t->max)
	{
		printf("turn >= t->max \n");
		return ;
	}
	if (is_sorted(stack_a, stack_b))
	{
		printf("is_sorted\n");
		update_ans(t, turn);
		return ;
	}
	while (ops++ <= rrr) 
	{
//		if (avoid_check(command, t) || turn >= t->max)
//			continue ;
		if (turn >= t->max)
			continue ;
		if (sort_dlst(stack_a, stack_b, ops, false))
		{
			t->tmp[turn] = ops;
			continue ;
		}
		dfs(stack_a, stack_b, t, turn + 1);
		printf("---Before---\n");
		print_stack(stack_a, stack_b);
		sort_dlst(stack_a, stack_b, ops, true);
		printf("---After---\n");
		print_stack(stack_a, stack_b);
	}
}
