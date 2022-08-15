/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/15 18:15:12 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
 *
*/

int dublicate(char *input)
{
	(void)input;
	return (1);
}

int is_int(char *input)
{
	(void)input;
	return (1);
}

int is_digit(char *input)
{
	(void)input;
	return (1);
}

int validate_args(int ac, char **av)
{
	if (ac < 2)
		return (0);
	(void)av;
	return (1);
}
