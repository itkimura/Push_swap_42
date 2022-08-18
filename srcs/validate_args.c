/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/18 12:22:18 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
 *
*/

int	is_valid_str(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] == '-' || av[i] == '+')
			&& !(av[i + 1] >= '0' && av[i + 1] <= '9'))
			return (0);
		if (!(av[i] >= '0' && av[i] <= '9')
			&& av[i] != ' ' && av[i] != '-' && av[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	validate_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!is_valid_str(av[i]))
			return (error());
		i++;
	}
	return (1);
}
