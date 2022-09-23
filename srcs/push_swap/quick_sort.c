/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/15 18:04:26 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_qs_condition(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int pivot)
{
	if (stack_b->next->index == t->a_next && stack_b->next != stack_b)
	{
		add_qsans(pa, stack_a, stack_b, t);
		add_qsans(ra, stack_a, stack_b, t);
		t->a_next++;
	}
	else if (t->a_next == stack_b->prev->index)
	{
		add_qsans(rrb, stack_a, stack_b, t);
		add_qsans(pa, stack_a, stack_b, t);
		add_qsans(ra, stack_a, stack_b, t);
		t->b_size++;
		t->a_next++;
	}
	else if (stack_b->next->index > pivot && stack_b->next != stack_b)
	{
		t->next_size[t->sort_turn]++;
		add_qsans(pa, stack_a, stack_b, t);
	}
	else
		add_qsans(rb, stack_a, stack_b, t);
}

void	b_quick_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;
	int	pivot;

	i = 0;
	pivot = t->a_next + ((t->b_size - 1) / 2);
	t->sort_turn++;
	while (i < t->b_size)
	{
		b_qs_condition(stack_a, stack_b, t, pivot);
		i++;
	}
}

void	b_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;

	i = 0;
	t->b_size = stack_size(stack_b);
	if (t->b_size)
		b_dfs(stack_a, stack_b, t, 0);
	while (i < t->max && t->ans[i] != -1)
	{
		add_qsans(t->ans[i], stack_a, stack_b, t);
		i++;
	}
	while (stack_b->next->index == t->a_next)
	{
		add_qsans(pa, stack_a, stack_b, t);
		add_qsans(ra, stack_a, stack_b, t);
		t->a_next++;
	}
	t->max = SORTLIMIT;
	t->prev = -1;
	ft_memset(t->tmp, -1, sizeof(t->tmp));
	ft_memset(t->ans, -1, sizeof(t->ans));
}

void	a_qs_condition(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	if (stack_b->prev->index == t->a_next)
		add_qsans(rrb, stack_a, stack_b, t);
	if (stack_b->next->next->index == t->a_next)
		add_qsans(sb, stack_a, stack_b, t);
	if (stack_b->next->index == t->a_next)
	{
		t->next_size[t->sort_turn]++;
		add_qsans(pa, stack_a, stack_b, t);
	}
	if (stack_a->next->next->index == t->a_next
		&& stack_a->next->index == t->a_next + 1)
		add_qsans(sa, stack_a, stack_b, t);
	if (stack_a->next->index == t->a_next)
	{
		add_qsans(ra, stack_a, stack_b, t);
		t->a_next++;
	}
	else
		add_qsans(pb, stack_a, stack_b, t);
}

void	a_quick_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;

	i = 0;
	while (i < t->next_size[t->sort_turn])
	{
		a_qs_condition(stack_a, stack_b, t);
		i++;
	}
	t->next_size[t->sort_turn] = 0;
	if (t->sort_turn)
		t->sort_turn--;
}
