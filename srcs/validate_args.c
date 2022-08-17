/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/17 17:30:36 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * return (0) = false
 * return (1) = true
 *
*/

int	dublicate(char *input)
{
	(void)input;
	return (1);
}

long int	ft_atoli(char *arg)
{
	long int	nb;
	int			flag;

	nb = 0;
	flag = 1;
	if (*arg == '-')
		flag = -1;
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg)
	{
		nb = nb * 10 + (*arg - '0');
		arg++;
	}
	return (nb * flag);
}

int	is_valid_letter(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] == '-' || arg[i] == '+') && !(arg[i + 1] >= '0' && arg[i + 1] <= '9'))
			return (0);
		if (!(*arg >= '0' && *arg <= '9') && *arg != ' ' && *arg != '-' && *arg != '+')
			return (0);
		i++;
	}
	return (1);
}

int nb_of_arg(char *arg)
{
	int	nb;

	nb = 0;
	while (*arg)
	{
		if (*arg != ' ')
		{
			nb++;
			while ((*arg >= '0' && *arg <= '9') || *arg == '-' || *arg == '+')
				arg++;
			if (!*arg)
				break ;
		}
		arg++;
	}
	return (nb);
}

t_dlst	*dlstnew(long int arg)
{
	t_dlst	*new;

	new = (t_dlst *)malloc(sizeof(t_dlst));
	if (!new)
		return (0);
	new->value = (long int)malloc(sizeof(long int));
	if (!new->value)
	{
		free(new);
		return (0);
	}
	new->value = arg;
	new->next = NULL;
	return (new);
}

int	validate_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		if (!is_valid_letter(av[i]))
			return (0);
		i++;
	}
	return (1);
}
