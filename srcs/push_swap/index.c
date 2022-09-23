/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/15 16:52:04 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	index_sort(int *index, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = index[left];
	i = left;
	j = right;
	while (1)
	{
		while (index[i] < pivot)
			i++;
		while (index[j] > pivot)
			j--;
		if (i >= j)
			break ;
		int_swap(&index[i], &index[j]);
		i++;
		j--;
	}
	index_sort(index, left, i - 1);
	index_sort(index, j + 1, right);
}

void	add_index(t_dlst *stack_a, int *index, int total)
{
	int		i;
	t_dlst	*tmp;

	tmp = stack_a->next;
	while (tmp != stack_a)
	{
		i = 0;
		while (i < total)
		{
			if (index[i] == tmp->value)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	init_index(t_dlst *stack_a, int total)
{
	int		i;
	int		*index;
	t_dlst	*tmp;

	i = 0;
	index = (int *)malloc(sizeof(int) * total);
	if (!index)
		return (0);
	tmp = stack_a->next;
	while (i < total)
	{
		index[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	index_sort(index, 0, total - 1);
	add_index(stack_a, index, total);
	free(index);
	return (1);
}
