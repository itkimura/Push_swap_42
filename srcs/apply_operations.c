/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/25 15:23:21 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/
int	apply_op(char *input, t_dlst *stack_a, t_dlst *stack_b)
{
	if (!ft_strcmp(input, "sa"))
		return (swap(stack_a));
	if (!ft_strcmp(input, "sb"))
		return (swap(stack_b));
	if (!ft_strcmp(input, "ss"))
		return (swap(stack_a) + swap(stack_b));
	if (!ft_strcmp(input, "pa"))
		return (push(stack_b, stack_a));
	if (!ft_strcmp(input, "pb"))
		return (push(stack_a, stack_b));
	if (!ft_strcmp(input, "ra"))
		return (rotate(stack_a));
	if (!ft_strcmp(input, "rb"))
		return (rotate(stack_b));
	if (!ft_strcmp(input, "rr"))
		return (rotate(stack_a) + rotate(stack_b));
	if (!ft_strcmp(input, "rra"))
		return (reverse(stack_a));
	if (!ft_strcmp(input, "rrb"))
		return (reverse(stack_b));
	if (!ft_strcmp(input, "rrr"))
		return (reverse(stack_a) + reverse(stack_b));
	return (0);
}
