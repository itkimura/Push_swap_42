/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:23:03 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/18 12:34:10 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	activate_display(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-v"))
			return (1);
		i++;
	}
	return (0);
}

int	new_checker(t_checker **checker)
{
	t_checker	*new;

	new = (t_checker *)malloc(sizeof(t_checker));
	if (!new)
		return (0);
	new->line = NULL;
	new->next = NULL;
	*checker = new;
	return (1);
}

void	free_checker(t_checker *c)
{
	t_checker	*tmp;
	t_checker	*next;

	tmp = c;
	while (tmp->next)
	{
		next = tmp->next;
		free(tmp->line);
		free(tmp);
		tmp = next;
	}
	free(tmp);
}
