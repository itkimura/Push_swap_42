/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/15 18:12:38 by itkimura         ###   ########.fr       */
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
		ft_putstr("sa\n");
	if (index == sb)
		ft_putstr("sb\n");
	if (index == ss)
		ft_putstr("ss\n");
	if (index == pa)
		ft_putstr("pa\n");
	if (index == pb)
		ft_putstr("pb\n");
	if (index == ra)
		ft_putstr("ra\n");
	if (index == rb)
		ft_putstr("rb\n");
	if (index == rr)
		ft_putstr("rr\n");
	if (index == rra)
		ft_putstr("rra\n");
	if (index == rrb)
		ft_putstr("rrb\n");
	if (index == rrr)
		ft_putstr("rrr\n");
}

void	print_ans(t_sort *t)
{
	int	i;

	i = 0;
	while (i < t->max)
		print_operations(t->ans[i++]);
}
