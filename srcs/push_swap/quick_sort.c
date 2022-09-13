/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/13 16:24:22 by itkimura         ###   ########.fr       */
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
	int	pivot;
	int	size;

	size = 0;
	pivot = t->total / 2;
	i = 0;
	while (i < t->total && size < pivot)
	{
		/* while the top b is b_next, do rb*/
		while(stack_b->next->index == t->b_next && stack_b->next != stack_b)
			if (b_next_keep(stack_a, stack_b, t, size))
				break ;
		/*if top is b_next + 1 and if next_b is not in stack_b, rotate_b*/
//		if (stack_b->next->index == t->b_next + 1 && !is_b_next_included(stack_b, t) && size > 1)
//			t->q_ans[t->turn++] = apply_and_add(rb, stack_a, stack_b);
//		if (stack_a->next->index == t->a_next + 1 && i == t->total - 2)
//			t->q_ans[t->turn++] = apply_and_add(sa, stack_a, stack_b);:w
		if (size == pivot - 2 && stack_a->next->index == t->a_next + 1 && stack_a->next->next->index == t->a_next)
		{
			t->q_ans[t->turn++] = apply_and_add(sa, stack_a, stack_b);
			t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
			t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
			size += 2;
			t->a_next += 2;
			continue;
		}
		if (stack_a->next->index < pivot)
//			&& (stack_a->next->index != t->a_next && i == t->total - 1))
		{
			t->q_ans[t->turn++] = apply_and_add(pb, stack_a, stack_b);
			size++;
		}
		else
		{
		if (stack_a->next->index == t->a_next)
				t->a_next++;
			t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
		}
		i++;
	}
	t->next_size[t->sort_turn] = stack_size(stack_a);
//	printf("half_size\n");
//	printf("◆t->next_size[%d] = %d\n", t->sort_turn, t->next_size[t->sort_turn]);
//	print_stack(stack_a, stack_b, t);
}

void	b_top(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;

	i = 0;
	while (i + t->a_next < t->b_next)
	{
		/* if the last b is b_next - 1 do rrb and put it on the top */
		if (stack_b->prev->index == t->b_next - i - 1)
			t->q_ans[t->turn++] = apply_and_add(rrb, stack_a, stack_b);
		/* if there are the second last of stack_b, do rrb twice
		 * b->[5]
		 * stack -> ....[4] [10] ->[10][4] ......
		 * */
		else if (stack_b->prev->prev->index == t->b_next - i - 1)
		{
			t->q_ans[t->turn++] = apply_and_add(rrb, stack_a, stack_b);
			t->q_ans[t->turn++] = apply_and_add(rrb, stack_a, stack_b);
		}
		/*if the top b is b_next - 1 then pa*/
		if (stack_b->next->index == t->b_next - i - 1)
		{
			t->q_ans[t->turn++] = apply_and_add(pa, stack_a, stack_b);
		}
		i++;
	}
	/*if the top a is same as a_next, move it to the last a */
	while (stack_a->next->index == t->a_next)
	{
		t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
		t->a_next++;
	}
//	printf("--- b_top ---\n");
//	printf("◆t->next_size[%d] = %d\n", t->sort_turn, t->next_size[t->sort_turn]);
//	print_stack(stack_a, stack_b, t);
}

void	b_quick_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t, int size)
{
	int	i;
	int	pivot;

	i = 0;
//	printf("size = %d\n", size);
	pivot = t->a_next + ((size - 1) / 2);
//	printf("size = %d\n", size);
	t->sort_turn++;
	while(i < size)
	{
		if (stack_b->next->index == t->a_next && stack_b->next != stack_b)
		{
			t->q_ans[t->turn++] = apply_and_add(pa, stack_a, stack_b);
			t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
			t->b_next++;
			t->a_next++;
		}
		else if (t->a_next == stack_b->prev->index)
		{
			t->q_ans[t->turn++] = apply_and_add(rrb, stack_a, stack_b);
			t->q_ans[t->turn++] = apply_and_add(pa, stack_a, stack_b);
			t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
			size++;
			t->b_next++;
			t->a_next++;
		}
		else if (stack_b->next->index > pivot && stack_b->next != stack_b)
		{
			t->next_size[t->sort_turn]++;
			t->q_ans[t->turn++] = apply_and_add(pa, stack_a, stack_b);
		}
		else
			t->q_ans[t->turn++] = apply_and_add(rb, stack_a, stack_b);
		i++;
	}
//	printf("--- b_quick_sort ---\n");
//	printf("◆t->next_size[%d] = %d\n", t->sort_turn, t->next_size[t->sort_turn]);
//	print_stack(stack_a, stack_b, t);
}

void	b_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;

	i = 0;
	while (t->a_next == stack_b->next->index)
	{
		t->q_ans[t->turn++] = apply_and_add(pa, stack_a, stack_b);
		t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
		t->b_next++;
		t->a_next++;
	}
	if ((t->b_size = stack_size(stack_b)))
		b_dfs(stack_a, stack_b, t, 0);
	while (i < t->max && t->ans[i] != -1)
	{
		apply_op(t->ans[i], stack_a, stack_b);
		t->q_ans[t->turn++] = t->ans[i];
		i++;
	}
	while (stack_b->next->index == t->a_next)
	{
		t->q_ans[t->turn++] = apply_and_add(pa, stack_a, stack_b);
		t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
		t->b_next++;
		t->a_next++;
	}
//	printf("--- b sort ---\n");
//	printf("t->next_size[%d] = %d\n", t->sort_turn, t->next_size[t->sort_turn]);
//	print_stack(stack_a, stack_b, t);
	t->max = SORTLIMIT;
	t->prev = -1;
	ft_memset(t->tmp, -1, sizeof(t->tmp));
	ft_memset(t->ans, -1, sizeof(t->ans));
}

void	a_quick_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;
	i = 0;
//	printf("Before:t->next_size[%d] = %d\n", t->sort_turn, t->next_size[t->sort_turn]);
	while (i < t->next_size[t->sort_turn])
	{
		if (stack_b->prev->index == t->a_next)
			t->q_ans[t->turn++] = apply_and_add(rrb, stack_a, stack_b);
		if (stack_b->next->next->index == t->a_next)
			t->q_ans[t->turn++] = apply_and_add(sb, stack_a, stack_b);
		if (stack_b->next->index == t->a_next)
		{
			t->next_size[t->sort_turn]++;
			t->q_ans[t->turn++] = apply_and_add(pa, stack_a, stack_b);
		}
		if (stack_a->next->next->index == t->a_next &&
		stack_a->next->index == t->a_next + 1)
			t->q_ans[t->turn++] = apply_and_add(sa, stack_a, stack_b);
		if (stack_a->next->index == t->a_next)
		{
			t->q_ans[t->turn++] = apply_and_add(ra, stack_a, stack_b);
			t->b_next++;
			t->a_next++;
		}
		else
			t->q_ans[t->turn++] = apply_and_add(pb, stack_a, stack_b);
		i++;
	}
	t->next_size[t->sort_turn] = 0;
	if (t->sort_turn)
		t->sort_turn--;
//	printf("After:t->next_size[%d] = %d\n", t->sort_turn, t->next_size[t->sort_turn]);
//	printf("--- a_quick_sort ---\n");
//	print_stack(stack_a, stack_b, t);

}

void	optimise(t_sort *t)
{
	int i;
//	int count;

	i = 0;
//	count = 0;
	while (i < t->turn)
	{
		if ((t->q_ans[i] == sa && t->q_ans[i + 1] == sb) ||
		(t->q_ans[i] == sb && t->q_ans[i + 1] == sa))
		{
//			printf("[%3d] ", count++);
			print_operations(ss);
			i += 2;
		}
		else if ((t->q_ans[i] == ra && t->q_ans[i + 1] == rb) ||
		(t->q_ans[i] == rb && t->q_ans[i + 1] == ra))
		{
//			printf("[%3d] ", count++);
			print_operations(rr);
			i += 2;
		}
		else if ((t->q_ans[i] == pa && t->q_ans[i + 1] == pb) ||
		(t->q_ans[i] == pb && t->q_ans[i + 1] == pa))
			i += 2;
		else
		{
//			printf("[%3d] ", count++);
			print_operations(t->q_ans[i]);
			i++;
		}
	}
}

int	big_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int size;
//	int i;

//	i = 0;
	if (!init_index(stack_a, t->total))
		return (0);
	half_size(stack_a, stack_b, t);
//	while (i < 20)
	while (!is_sorted(stack_a, stack_b))
	{
		b_top(stack_a, stack_b,t);
		while ((size = stack_size(stack_b)) > 3)
			b_quick_sort(stack_a, stack_b, t, size);
		b_sort(stack_a, stack_b, t);
		while (stack_size(stack_b) == 0 && !is_sorted(stack_a, stack_b))
			a_quick_sort(stack_a, stack_b, t);
	//	i++;
	}
//	printf("\n--- End result ---\n");
//	for(int i = 0; i < t->turn; i++)
//	{
//		printf("[%3d] ", i);
//		print_operations(t->q_ans[i]);
//	}
//	printf("Optimise ver\n");
	optimise(t);
//	print_detail(stack_a, stack_b);
//	print_stack(stack_a, stack_b, t);
//	if (!is_sorted(stack_a, stack_b))
//			ft_putstr("KO\n");
//		else
//			ft_putstr("OK\n");
//	printf("\n");
	return (1);
}
