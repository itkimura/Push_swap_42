/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/02 18:10:22 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Insid of mail function:
 * return (0) = successfully
 * return (1) = Error
 * 
*/

void	print_operations(int index)
{
	if (index == sa)
		printf("sa\n");
	if (index == sb)
		printf("sb\n");
	if (index == ss)
		printf("ss\n");
	if (index == pa)
		printf("pa\n");
	if (index == pb)
		printf("pb\n");
	if (index == ra)
		printf("ra\n");
	if (index == rb)
		printf("rb\n");
	if (index == rr)
		printf("rr\n");
	if (index == rra)
		printf("rra\n");
	if (index == rrb)
		printf("rrb\n");
	if (index == rrr)
		printf("rrr\n");
}

void	print_ans(t_sort *t)
{
	int	i;

	i = 0;
	while (i < t->max)
		print_operations(t->ans[i++]);
}
