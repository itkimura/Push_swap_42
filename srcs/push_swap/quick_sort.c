/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/07 16:49:17 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if the number of b next index is on the top -> rb */

int		b_next_keep(t_dlst *stack_b, t_sort *t)
{
	t->b_next_index++;
	if (t->b_size == 1)
		return (1);
	if (stack_b->prev->index == t->b_next_index)
		t->b_next_index++;
	rotate(stack_b);
	t->ans[t->total_turn++] = rb;
	return (0);
}

void	half_size(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	pivot;
	int i;

	t->quick_sort = (int *)malloc(sizeof(int) * (t->total * 2));
	pivot = t->total / 2;
	i = 0;
	while (i < t->total && t->b_size < pivot)
	{
		while (stack_b->next->index == t->b_next_index)
		{
			if (b_next_keep(stack_b, t))
				break;
		}
		if (stack_a->next->index >= pivot)
		{
			rotate(stack_a);
			t->quick_sort[t->total_turn++] = ra;
		}
		else
		{
			push(stack_a, stack_b);
			t->quick_sort[t->total_turn++] = pb;
		}
		i++;
	}
	t->b_size = stack_size(stack_b);
}

void	add_answer(t_sort *t, int *ans, int ans_size)
{
	int	i;
	int	len;
	int	*new;

	len = t->total_turn + ans_size;
	printf("len = %d\n", len);
	new = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		if (i < t->total_turn)
			new[i] = t->quick_sort[i];
		else
			new[i] = ans[i - t->total_turn];
		i++;
	}
	free(t->quick_sort);
	t->total_turn += ans_size;
	t->quick_sort = new;
}

void	b_quick_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int		i;
	int		pivot;
	int		b_total;
	int		*ans;

	i = 0;
	b_total = stack_size(stack_b);
	pivot = b_total / 2;
	ans = (int *)malloc(sizeof(int) * b_total);
	while (i < b_total)
	{
		printf("t->a_next_index = %d stack_b->next->index = %d stack_b->next->value = %d\n", t->a_next_index, stack_b->next->index, stack_b->next->value);
		if (stack_b->next->index == t->a_next_index)
		{
			push(stack_b, stack_a);
			rotate(stack_a);
			ans[i++] = pa;
			ans[i++] = rra;
			t->a_next_index++;
		}
		else if (stack_b->next->index >= pivot)
		{
			push(stack_b, stack_a);
			ans[i++] = pa;
		}
		else
		{
			rotate(stack_b);
			ans[i++] = rb;
		}
		i++;
	}
	print_stack(stack_a, stack_b);
	add_answer(t, ans, i);
	free(ans);
}

void	b_top(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int	i;
	int *ans;

	i = 0;
	ans = (int *)malloc(sizeof(int) * t->b_size);
	printf("t->b_next_index = %d\n", t->b_next_index);
	while (i + t->a_next_index < t->b_next_index)
	{
		if (stack_b->prev->index == t->b_next_index - i - 1)
		{
			reverse(stack_b);
			ans[i] = rb;
		}
		else if (stack_b->prev->prev->index == t->b_next_index - i - 1)
		{
			reverse(stack_b);
			reverse(stack_b);
			ans[i++] = rb;
			ans[i] = rb;
		}
		else if (stack_b->next->index == t->b_next_index - i - 1)
		{
			push(stack_b, stack_a);
			ans[i] = pa;
		}
		i++;
	}
	while (stack_a->next->index == t->a_next_index)
	{
		rotate(stack_a);
		ans[i++] = ra;
		t->a_next_index++;
	}
	printf("i = %d\n", i);
	add_answer(t, ans, i - t->b_next_index);
	free(ans);
}

void	b_dfs_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	int i;
	int *ans;

	i = 0;
	b_dfs(stack_a, stack_b, t, 0);
	t->total_turn += t->max;
	add_answer(t, t->ans, t->max);
	while (i < t->max)
		apply_op(t->ans[i++], stack_a, stack_b);
	ft_memset(t->tmp, -1, sizeof(t->tmp));
	ft_memset(t->ans, -1, sizeof(t->ans));
	t->max = SORTLIMIT;
	i++;
	ans = (int *)malloc(sizeof(int) * t->b_size);
	while(stack_b->next != stack_b)
	{
		push(stack_b, stack_a);
		rotate(stack_a);
		ans[i++] = pa;
		ans[i++] = ra;
		t->a_next_index++;
		t->b_next_index++;
	}
	add_answer(t, ans, i);
	free(ans);
}

int	big_sort(t_dlst *stack_a, t_dlst *stack_b, t_sort *t)
{
	if (!init_index(stack_a, t->total))
		return (0);
		printf("half_size\n");
	half_size(stack_a, stack_b, t);
	print_stack(stack_a, stack_b);
	while (t->a_next_index != t->total)
	{
		printf("b_top\n");
		print_stack(stack_a, stack_b);
		b_top(stack_a, stack_b, t);
		while ((t->b_size = stack_size(stack_b)) > 4)
			b_quick_sort(stack_a, stack_b, t);
		printf("b_quick_sort\n");
		print_stack(stack_a, stack_b);
		b_dfs_sort(stack_a, stack_b, t);
		printf("after dfs\n");
		print_stack(stack_a, stack_b);
		break ;
	}
	/*
	int turn;
	turn = 0;
	t->b_size = 3;
	for (int i = 0; i < t->max; i++)
		apply_op(t->ans[i], stack_a, stack_b);
	add_answer(t, t->ans, t->max);
	print_stack(stack_a, stack_b);
	*/
	printf("End result \n");
	int count;
	for(count = 0; count < t->total_turn; count++)
		print_operations(t->quick_sort[count]);
	printf("count = %d\n", count);
	free(t->quick_sort);
	return (1);
}
