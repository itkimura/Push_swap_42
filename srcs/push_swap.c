/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/24 16:10:05 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Insid of mail function:
 * return (0) = successfully
 * return (1) = Error
 * 
*/

int	main(int ac, char **av)
{
	t_dlst	*stack_a;
	t_dlst	*stack_b;

	if (ac >= 2)
	{
		stack_a = dlstnew(NULL, 0);
		stack_b = dlstnew(NULL, 0);
		if (!stack_a || !stack_b)
			return (1);
		if (!init_stack(ac, av, &stack_a))
			return (1);
		ft_putstr("OK\n");
	}
	return (0);
}
