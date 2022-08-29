/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/29 11:14:43 by itkimura         ###   ########.fr       */
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

int	is_sorted(t_dlst *a, t_dlst *b)
{
	t_dlst	*tmp;

	tmp = a->next;
	if (b->next != b)
		return (0);
	while (tmp != a)
	{
		if (tmp->value > tmp->next->value && tmp->next != a)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	dublicate_check(int nb, t_dlst **curr)
{
	t_dlst	*tmp;

	tmp = *curr;
	while (tmp->prev)
	{
		if (nb == tmp->value)
		{
			printf("Duplication\n");
			return (0);
		}
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
		{
			printf("Non numeric number\n");
			return (0);
		}
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
		if (!is_valid_nb(str, &i))
			return (0);
		if (!add_stack(&str[start], curr, total))
			return (0);
		if (str[i])
			i++;
	}
	return (1);
}
