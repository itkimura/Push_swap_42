/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/15 16:30:36 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	new_qsans(t_qsans **a)
{
	t_qsans	*new;

	new = (t_qsans *)malloc(sizeof(t_qsans));
	if (!new)
		return (0);
	new->index = 0;
	new->next = NULL;
	*a = new;
	return (1);
}

/* if the number of b next index is on the top -> rb */
void	add_qsans(int op, t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	t_qsans *new;

	if (!new_qsans(&new))
		exit(0);
	(void)stack_a;
	(void)stack_b;
	apply_op(op, stack_a, stack_b);
	new->index = op;
	new->next = NULL;
	t->q_last->next = new;
	t->q_last = new;
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
	add_qsans(rb, stack_a, stack_b, t);
	return (1);
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
		if (size == pivot - 2 && stack_a->next->index == t->a_next + 1 && stack_a->next->next->index == t->a_next)
		{
			add_qsans(sa, stack_a, stack_b, t);
			add_qsans(ra, stack_a, stack_b, t);
			add_qsans(ra, stack_a, stack_b, t);
			size += 2;
			t->a_next += 2;
			continue;
		}
		if (stack_a->next->index < pivot)
		{
			add_qsans(pb, stack_a, stack_b, t);
			size++;
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
			add_qsans(rrb, stack_a, stack_b, t);
		/* if there are the second last of stack_b, do rrb twice
		 * b->[5]
		 * stack -> ....[4] [10] ->[10][4] ......
		 * */
		else if (stack_b->prev->prev->index == t->b_next - i - 1)
		{
			add_qsans(rrb, stack_a, stack_b, t);
			add_qsans(rrb, stack_a, stack_b, t);
		}
		/*if the top b is b_next - 1 then pa*/
		if (stack_b->next->index == t->b_next - i - 1)
			add_qsans(pa, stack_a, stack_b, t);
		i++;
	}
	/*if the top a is same as a_next, move it to the last a */
	while (stack_a->next->index == t->a_next)
	{
		add_qsans(ra, stack_a, stack_b, t);
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
			add_qsans(pa, stack_a, stack_b, t);
			add_qsans(ra, stack_a, stack_b, t);
			t->b_next++;
			t->a_next++;
		}
		else if (t->a_next == stack_b->prev->index)
		{
			add_qsans(rrb, stack_a, stack_b, t);
			add_qsans(pa, stack_a, stack_b, t);
			add_qsans(ra, stack_a, stack_b, t);
			size++;
			t->b_next++;
			t->a_next++;
		}
		else if (stack_b->next->index > pivot && stack_b->next != stack_b)
		{
			t->next_size[t->sort_turn]++;
			add_qsans(pa, stack_a, stack_b, t);
		}
		else
			add_qsans(rb, stack_a, stack_b, t);
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
		add_qsans(pa, stack_a, stack_b, t);
		add_qsans(ra, stack_a, stack_b, t);
		t->b_next++;
		t->a_next++;
	}
	if ((t->b_size = stack_size(stack_b)))
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
			add_qsans(rrb, stack_a, stack_b, t);
		if (stack_b->next->next->index == t->a_next)
			add_qsans(sb, stack_a, stack_b, t);
		if (stack_b->next->index == t->a_next)
		{
			t->next_size[t->sort_turn]++;
			add_qsans(pa, stack_a, stack_b, t);
		}
		if (stack_a->next->next->index == t->a_next &&
		stack_a->next->index == t->a_next + 1)
			add_qsans(sa, stack_a, stack_b, t);
		if (stack_a->next->index == t->a_next)
		{
			add_qsans(ra, stack_a, stack_b, t);
			t->b_next++;
			t->a_next++;
		}
		else
			add_qsans(pb, stack_a, stack_b, t);
		i++;
	}
	t->next_size[t->sort_turn] = 0;
	if (t->sort_turn)
		t->sort_turn--;
//	printf("After:t->next_size[%d] = %d\n", t->sort_turn, t->next_size[t->sort_turn]);
//	printf("--- a_quick_sort ---\n");
//	print_stack(stack_a, stack_b, t);

}

void	qsans_print(t_qsans *a)
{
	int count;
	int i;
	
	count = 0;
	i = 0;
	a = a->next;
	while (a->next != NULL)
	{
		//printf("size= %d i = %d ", size, i);
		if (((a->index == sa && a->next->index == sb) ||
		(a->index == sb && a->next->index == sa)) && a->next->next)
		{
			count++;
//			printf("[%3d] ", count++);
			print_operations(ss);
			a = a->next->next;
		}
		else if (((a->index == ra && a->next->index == rb) ||
		(a->index == rb && a->next->index == ra)) && a->next->next)
		{
			count++;
//			printf("[%3d] ", count++);
			print_operations(rr);
			a = a->next->next;
		}
		else if (((a->index == pa && a->next->index == pb) ||
		(a->index == pb && a->next->index == pa)) && a->next->next)
			a = a->next->next;
		else
		{
			count++;
//			printf("[%3d] ", count++);
			print_operations(a->index);
			a = a->next;
		}
		i++;
	}
	print_operations(a->index);
//	printf ("a->index = %d\n", a->index);
//	printf("count = %d\n", count);
}

void free_qsans(t_qsans **a)
{
	t_qsans *tmp;
	t_qsans *next;

	next = (*a);
	while (next)
	{
		tmp = next->next;
		free(next);
		next = tmp;
	}

}

int	big_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int size;
	t_qsans *head;

	if (!init_index(stack_a, t->total))
		return (0);
	if (!new_qsans(&head))
		return (0);
	t->q_last = head;
	half_size(stack_a, stack_b, t);
	b_top(stack_a, stack_b,t);
	while (!is_sorted(stack_a, stack_b))
	{
		while ((size = stack_size(stack_b)) > 3)
			b_quick_sort(stack_a, stack_b, t, size);
		b_sort(stack_a, stack_b, t);
		while (stack_size(stack_b) == 0 && !is_sorted(stack_a, stack_b))
			a_quick_sort(stack_a, stack_b, t);
	}
//	print_stack(stack_a, stack_b, t);
//	printf("\n--- End result ---\n");
//	for(int i = 0; i < t->turn; i++)
//	{
//		printf("[%3d] ", i);
//		print_operations(t->q_ans[i]);
//	}
//	printf("Optimise ver\n");
//	optimise(t);
//	printf("count = %d\n", t->turn);
//	printf("qsans\n");
	qsans_print(head);
	free_qsans(&head);
//	print_detail(stack_a, stack_b);
//	print_stack(stack_a, stack_b, t);
//	if (!is_sorted(stack_a, stack_b))
//			ft_putstr("KO\n");
//		else
//			ft_putstr("OK\n");
	return (1);
}
