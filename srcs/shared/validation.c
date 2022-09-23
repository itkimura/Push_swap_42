/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/23 13:53:48 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
*/
void	error(void)
{
	ft_putstr_fd("Error\n", 2);
}

int	dublicate_check(int nb, t_dlst **curr)
{
	t_dlst	*tmp;

	tmp = *curr;
	while (tmp->prev)
	{
		if (nb == tmp->value)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

int	is_valid_nb(char *str, int *i)
{
	if ((str[*i] == '-' || str[*i] == '+'))
		(*i)++;
	while (str[*i] != ' ' && str[*i])
	{
		if (!(str[*i] >= '0' && str[*i] <= '9'))
			return (0);
		if (str[*i])
			(*i)++;
	}
	return (1);
}

int	is_valid_str(char *str, t_dlst **curr, int *total)
{
	int	i;
	int	start;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		start = i;
		if (!str[i])
			break ;
		if (!is_valid_nb(str, &i) && str[i])
			return (0);
		if (!add_stack(&str[start], curr, total))
			return (0);
		if (str[i])
			i++;
	}
	return (1);
}
