/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/24 16:12:19 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
 *
*/
int	error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int	is_valid_nb(char *str, int *i)
{
	if ((str[*i] == '-' || str[*i] == '+'))
		(*i)++;
	while (str[*i] != ' ' && str[*i])
	{
		if (!(str[*i] >= '0' && str[*i] <= '9'))
		{
			printf("Non numeric number\n");
			return (0);
		}
		if (str[*i])
			(*i)++;
	}
	return (1);
}

int	is_valid_str(char *str, t_dlst **curr)
{
	int	i;
	int	start;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		start = i;
		if (!is_valid_nb(str, &i))
			return (0);
		if (!add_stack(&str[start], curr))
			return (0);
		if (str[i])
			i++;
	}
	return (1);
}
