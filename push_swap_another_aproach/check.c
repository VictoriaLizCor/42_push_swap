/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/02/02 14:01:12 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_integers(char **argv)
{
	char	*copy;

	while (*argv)
	{
		if (!*argv)
			ft_error();
		copy = *(argv);
		if (ft_strchr("+-", *copy) || \
			ft_isdigit(*copy))
				copy++;
		while (*copy && ft_isdigit(*copy))
			copy++;
		if (!ft_isdigit(*copy))
		{
			if (!*copy)
				argv++;
			else
				ft_error();
		}
	}
}

void	check_repeated(t_stack *stack)
{
	t_stack	*copy;

	while (stack->next)
	{
		copy = stack->next;
		while (copy)
		{
			if (copy->value == stack->value)
				ft_error();
			copy = copy->next;
		}
		stack = stack->next;
	}
}
