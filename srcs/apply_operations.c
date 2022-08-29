/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/29 17:03:29 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(char *input)
{
	int		i;
	char	**str;


	i = 0;
	str = (char *[]){"sa", "sb", "ss", "pa", "pb", "ra",
					 "rb", "rr", "rra", "rrb", "rrr"};
	while (i < 11)
	{
		if (!ft_strcmp(str[i], input))
			break ;
		i++;
	}
	return (i);
}

int	recover_dlst(t_dlst *stack_a, t_dlst *stack_b, int index)
{
	if (index == sa)
		return (swap(stack_b));
	if (index == sb)
		return (swap(stack_a));
	if (index == ss)
		return (swap(stack_a) + swap(stack_b));
	if (index == pa)
		return (push(stack_a, stack_a));
	if (index == pb)
		return (push(stack_b, stack_a));
	if (index == ra)
		return (reverse(stack_a));
	if (index == rb)
		return (reverse(stack_b));
	if (index == rr)
		return (reverse(stack_a) + reverse(stack_b));
	if (index == rra)
		return (rotate(stack_a));
	if (index == rrb)
		return (rotate(stack_b));
	if (index == rrr)
		return (rotate(stack_a) + rotate(stack_b));
	return (index);
}

bool	sort_dlst(t_dlst *stack_a, t_dlst *stack_b, int index, bool recover)
{
	if (recover == true)
		return (recover_dlst(stack_a, stack_b, index));
	else
		return (apply_op(index, stack_a, stack_b));
	return (true);
}

int	apply_op(int index, t_dlst *stack_a, t_dlst *stack_b)
{
	if (index == sa)
		return (swap(stack_a));
	if (index == sb)
		return (swap(stack_b));
	if (index == ss)
		return (swap(stack_a) + swap(stack_b));
	if (index == pa)
		return (push(stack_b, stack_a));
	if (index == pb)
		return (push(stack_a, stack_b));
	if (index == ra)
		return (rotate(stack_a));
	if (index == rb)
		return (rotate(stack_b));
	if (index == rr)
		return (rotate(stack_a) + rotate(stack_b));
	if (index == rra)
		return (reverse(stack_a));
	if (index == rrb)
		return (reverse(stack_b));
	if (index == rrr)
		return (reverse(stack_a) + reverse(stack_b));
	return (0);
}
