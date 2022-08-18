/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/18 15:07:18 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
*/

/* Check duplication in int string */

int	dublicate_check(int *numbers, int *total)
{
	int	i;
	int	j;

	i = 0;
	while (i < *total)
	{
		j = 0;
		while (j < i)
		{
			if (numbers[j] == numbers[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Count the number of int in a string(av) */

int	number_of_ints(char *av)
{
	int	nb;

	nb = 0;
	while (*av)
	{
		if (*av != ' ')
		{
			nb++;
			while ((*av >= '0' && *av <= '9') || *av == '-' || *av == '+')
				av++;
			if (!*av)
				break ;
		}
		av++;
	}
	return (nb);
}

/* convert char to long int */

long int	ft_atoli(char *av)
{
	int			flag;
	long int	nb;

	nb = 0;
	flag = 1;
	while (*av == ' ')
		av++;
	if (*av == '-')
		flag = -1;
	if (*av == '-' || *av == '+')
		av++;
	while (*av >= '0' && *av <= '9')
	{
		nb = nb * 10 + (*av - '0');
		av++;
	}
	return (nb * flag);
}

/*
 * Devides each numbers in strings
 * For example, *arg = "   1 2 3"; ->
 * nums[0] = 1;
 * nums[1] = 2;
 * nums[2] = 3;
*/

int	devide_numbers(int ac, char **av, int *numbers, int *count)
{
	int			i;
	long int	tmp;

	i = 1;
	while (i < ac)
	{
		while (*av[i])
		{
			while (*av[i] == ' ')
				av[i]++;
			tmp = (ft_atoli(av[i]));
			while ((*av[i] >= '0' && *av[i] <= '9')
				|| *av[i] == '-' || *av[i] == '+')
				av[i]++;
			if (tmp < INT_MIN || tmp > INT_MAX)
				return (0);
			else
				numbers[(*count)++] = (int)tmp;
			if (*av[i])
			av[i]++;
		}
		i++;
	}
	return (1);
}

/* initiarize numbers into the int string from argument value (char) */

int	init_numbers(int ac, char **av, int **numbers, int *total)
{
	int	i;
	int	count;

	i = 1;
	*total = 0;
	count = 0;
	while (i < ac)
	{
		(*total) += number_of_ints(av[i]);
		i++;
	}
	i = 1;
	*numbers = (int *)malloc(sizeof(int) * *total);
	if (!numbers)
		return (error());
	if (!devide_numbers(ac, av, *numbers, &count))
		return (error());
	if (!dublicate_check(*numbers, total))
		return (error());
	return (1);
}
