/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:31:41 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/17 15:39:49 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Insid of mail function:
 * return (0) = successfully
 * return (1) = Error
 * 
*/

/*
 * t_dlst	*stack_a;
 * t_dlst	*stack_b;
 * int		*list;
 *
 * stack_a = NULL;
 * stack_b = NULL;
 * list = NULL;
*/

int	main(int ac, char **av)
{
	if (!validate_args(ac, av))
	{
		ft_putstr("ERROR\n");
		return (1);
	}
	else
	{
		ft_putstr("OK\n");
		return (0);
	}
}
