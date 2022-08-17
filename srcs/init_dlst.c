/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:52:01 by itkimura          #+#    #+#             */
/*   Updated: 2022/08/17 17:50:44 by itkimura         ###   ########.fr       */
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

int	init_dlst(int ac, char **av)
{
}
