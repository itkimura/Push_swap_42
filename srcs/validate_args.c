/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/17 11:45:11 by itkimura         ###   ########.fr       */
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

int is_int(char *arg)
{
	long int	nb;
	int			flag;

	nb = 0;
	flag = 1;
	if (*arg == '-')
	{
		flag = -1;
		arg++;
	}
	while(*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (0);
		else
			nb = nb * 10 + (*arg - '0');
		arg++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

int is_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
		i++;
	}
		printf("arg = %d\n", ft_atoi(arg));
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN)
	{
		printf("arg = %d\n", ft_atoi(arg));
		return (0);
	}
	return (1);
}

int validate_args(int ac, char **av)
{
	int i;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!is_digit(av[i]) || !is_int(av[i]))
			return (0);
		i++;
	}
	return (1);
}
