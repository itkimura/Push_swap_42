/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/18 17:04:49 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Insid of mail function:
 * return (0) = successfully
 * return (1) = Error
 * 
*/

int	error(void)
{
	ft_putstr("ERROR\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;
	int		*numbers;
	int		total;

	stack_a = NULL;
	stack_b = NULL;
	numbers = NULL;
	if (!validate_args(ac, av) || !init_numbers(ac, av, &numbers, &total) 
		|| !init_stack(&stack_a, &stack_b, numbers, total))
		return (1);
	ft_putstr("OK\n");
	printf("stack_a = %d\n", *stack_a->value);
	return (0);
}
