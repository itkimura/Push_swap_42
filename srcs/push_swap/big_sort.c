/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/15 18:04:55 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if the number of b next index is on the top -> rb */

/* 
 * Check if the top of stack_a is what b wants next
 * If there are no index in B, nothing to do
 * if b's last number is what B want next, rb 
*/

int	b_next_keep(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	t->b_next++;
	if (t->b_size == 1)
		return (1);
	if (stack_b->prev->index == t->b_next)
		t->b_next++;
	add_qsans(rb, stack_a, stack_b, t);
	return (1);
}

void	half_size(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;
	int	pivot;

	t->b_size = 0;
	pivot = t->total / 2;
	i = 0;
	while (i < t->total && t->b_size < pivot)
	{
		while (stack_b->next->index == t->b_next && stack_b->next != stack_b)
			if (b_next_keep(stack_a, stack_b, t))
				break ;
		if (stack_a->next->index < pivot)
		{
			add_qsans(pb, stack_a, stack_b, t);
			t->b_size++;
		}
		else
		{
			if (stack_a->next->index == t->a_next)
				t->a_next++;
			add_qsans(ra, stack_a, stack_b, t);
		}
		i++;
	}
	t->next_size[t->sort_turn] = stack_size(stack_a) - t->a_next;
}

/* 
 * [1.while]
 * if the last b is b_next - 1 do rrb and put it on the top 
 * [2.while]
 * if there are the second last of stack_b, do rrb twice
 * b_next->[5]
 * stack -> ....[4] [10] ->[10][4] ......
 * 3.if the top b is b_next - 1 then pa
 * 4.if the top a is same as a_next, move it to the last a
*/
void	b_top(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;

	i = 0;
	while (i + t->a_next < t->b_next)
	{
		if (stack_b->prev->index == t->b_next - i - 1)
			add_qsans(rrb, stack_a, stack_b, t);
		else if (stack_b->prev->prev->index == t->b_next - i - 1)
		{
			add_qsans(rrb, stack_a, stack_b, t);
			add_qsans(rrb, stack_a, stack_b, t);
		}
		if (stack_b->next->index == t->b_next - i - 1)
			add_qsans(pa, stack_a, stack_b, t);
		i++;
	}
	while (stack_a->next->index == t->a_next)
	{
		add_qsans(ra, stack_a, stack_b, t);
		t->a_next++;
	}
}

int	big_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	t_qsans	*head;

	if (!init_index(stack_a, t->total))
		return (0);
	if (!new_qsans(&head))
		return (0);
	t->q_last = head;
	half_size(stack_a, stack_b, t);
	b_top(stack_a, stack_b, t);
	while (!is_sorted(stack_a, stack_b))
	{
		t->b_size = stack_size(stack_b);
		while (t->b_size > 3)
		{
			b_quick_sort(stack_a, stack_b, t);
			t->b_size = stack_size(stack_b);
		}
		b_sort(stack_a, stack_b, t);
		while (stack_size(stack_b) == 0 && !is_sorted(stack_a, stack_b))
			a_quick_sort(stack_a, stack_b, t);
	}
	qsans_print(head);
	free_qsans(&head);
	return (1);
}
