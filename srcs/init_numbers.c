/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/20 21:14:42 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
*/

/* Check duplication in int string */

int	is_valid_nb(char *str, int *i)
{
	if ((str[*i] == '-' || str[*i] == '+'))
	{
		if (!(str[*i + 1] >= '0' && str[*i + 1] <= '9'))
		{
			printf("Too many sign\n");
			return (0);
		}
		(*i)++;
	}
	while (str[*i] != ' ' && str[*i])
	{
		if (!(str[*i] >= '0' && str[*i] <= '9'))
		{
			printf("Non numeric number\n");
			return (0);
		}
		(*i)++;
	}
	return (1);
}
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
			{
				printf("dablicate numbers\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
 * Check all letter are valid
 * 1st if -> Non numeric letter
 * 2nd if -> Count the number of int in a string(av)
*/

int	is_valid_str(int ac, char **av, int *total)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (!is_valid_nb(av[i], &j))
				return (0);
			(*total)++;
			if (av[i][j])
				j++;
		}
		i++;
	}
	return (1);
}

/* convert char to long int */

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
			tmp = ft_atoli(av[i]);
			if (tmp < INT_MIN || tmp > INT_MAX)
			{
				printf("INT_MIN or INT_MAX\n");
				return (0);
			}
			numbers[(*count)++] = (int)tmp;
			while ((*av[i] >= '0' && *av[i] <= '9') || *av[i] == '-' || *av[i] == '+')
				av[i]++;
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
	int	count;

	*total = 0;
	count = 0;
	if (!is_valid_str(ac, av, total))
			return (error());
	*numbers = (int *)malloc(sizeof(int) * *total);
	if (!numbers || !devide_numbers(ac, av, *numbers, &count) 
		|| !dublicate_check(*numbers, total))
		return (error());
	return (1);
}
