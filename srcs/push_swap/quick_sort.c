/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/08 15:16:27 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if the number of b next index is on the top -> rb */

int	apply_and_add(int op, t_dlst *stack_a, t_dlst *stack_b)
{
	apply_op(op, stack_a, stack_b);
	return(op);
}

/* 
 * Check if the top of stack_a is what b wants next
 * If there are no index in B, nothing to do
 * if b's last number is what B want next, rb 
*/

int		b_next_keep(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int size)
{
	t->b_next++;
	if (size == 1)
		return (1);
	if (stack_b->prev->index == t->b_next)
		t->b_next++;
	t->q_ans[t->turn++] = apply_and_add(rb, stack_a, stack_b);
	return (1);
}

/* Check if b_next is included in stack_b */

int		is_b_next_included(t_dlst *stack_b, t_sort *t)
{
	t_dlst	*tmp;

	tmp = stack_b->next;
	while(tmp != stack_b)
	{
		if(tmp->index == t->b_next)
			return (1);
		tmp = tmp->next;
	}
	return (0);

}

void	half_size(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;
	int	size;
	int	pivot;

	size = 0;
	pivot = t->total / 2;
	t->q_ans = (int *)malloc(sizeof(int) * t->total);
	i = 0;
	while (i < t->total && size < pivot)
	{
		while(stack_b->next->index == t->b_next)
			if (b_next_keep(stack_a, stack_b, t, size))
				break ;
		/*if top is b_next + 1 and if next_b is not in stack_b, rotate_b*/
		if (stack_b->next->index == t->b_next + 1 && !is_b_next_included(stack_b, t) && size > 1)
			t->q_ans[t->turn++] = apply_and_add(rb, stack_a, stack_b);
		if (stack_a->next->index < pivot)
		{
			t->q_ans[t->turn++] = apply_and_add(pb, stack_a, stack_b);
			size++;
		}
		else
			t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
		i++;
		print_stack(stack_a, stack_b);
	}
}

int	big_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int size;
	if (!init_index(stack_a, t->total))
		return (0);
	printf("half_size\n");
	half_size(stack_a, stack_b, t);
	printf("t->b_next = %d\n", t->b_next);
	print_stack(stack_a, stack_b);
	(void)size;
	printf("\n--- End result ---\n");
	for(int i = 0; i < t->turn; i++)
	{
		printf("[%3d] ", i);
		print_operations(t->q_ans[i]);
	}
	printf("\n");
	free(t->q_ans);
	return (1);
}
