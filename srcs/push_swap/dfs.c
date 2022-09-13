/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:14:39 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/08 21:55:09 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_ans(t_sort *t, int turn)
{
	int	i;

	t->max = turn;
	i = 0;
	while (i < turn)
	{
		t->ans[i] = t->tmp[i];
		i++;
	}
}

void	b_dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn)
{
	int	ops;

	ops = -1;
	if (turn >= t->max)
		return ;
	if (is_b_sorted(stack_b))
		return (update_ans(t, turn));
	while (++ops <= rrr)
	{
		if (avoid_check(ops, t) || turn >= t->max)
			continue ;
		if (!sort_dlst(stack_a, stack_b, ops, false))
			continue ;
		t->prev = ops;
		t->tmp[turn] = ops;
		b_dfs(stack_a, stack_b, t, turn + 1);
		sort_dlst(stack_a, stack_b, ops, true);
	}
}

void	dfs(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int turn)
{
	int	ops;

	ops = -1;
	if (turn >= t->max)
		return ;
	if (is_sorted(stack_a, stack_b))
		return (update_ans(t, turn));
	while (++ops <= rrr)
	{
		if (avoid_check(ops, t) || turn >= t->max)
			continue ;
		if (!sort_dlst(stack_a, stack_b, ops, false))
			continue ;
		t->prev = ops;
		t->tmp[turn] = ops;
		dfs(stack_a, stack_b, t, turn + 1);
		sort_dlst(stack_a, stack_b, ops, true);
	}
}
