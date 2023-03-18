/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:45:00 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/12 17:50:50 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			ft_error(int i)
{
	write(3, "ERROR\n", ft_strlen("ERROR\n"));
	return (i);
}

int			ft_check_num(char *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] >= '0' && s[i] <= '9')
				i++;
			else
				return (-1);
		}
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		i;
	int		v;
	t_list	*la;
	t_list	*lb;

	la = NULL;
	lb = NULL;
	i = 1;
	v = 0;
	if (ac == 1)
		return (ft_error(0));
	if (ft_strcmp(av[1], "-v") == 0)
		v = 1;
	while (i < ac)
	{
		if (ft_check_num(av[i]) == 1)
			ft_fill(&la, ft_atoi(av[i]));
		i++;
	}
	ft_pushswap(la, lb, v);
	write (1, "\n", 1);
}
