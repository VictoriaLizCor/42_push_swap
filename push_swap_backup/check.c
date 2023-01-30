/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/25 11:43:35 by lilizarr         ###   ########.fr       */
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

int	check_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_idx(t_stack *head)
{
	t_stack	*stack;

	stack = head;
	while (stack)
	{
		if (stack->s_idx == 0)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_index(t_stack *stack)
{
	t_stack	*head;
	t_stack	*head_cpy;
	int		cnt;

	cnt = 0;
	head = stack;
	head_cpy = stack;
	while (stack)
	{
		if (stack->s_idx == 0 && find_min(head) == stack->value)
			stack->s_idx = ++cnt;
		stack = stack->next;
		if (stack == NULL)
			stack = head;
		if (check_sorted_idx(head))
			break ;
	}
	update_weight(head_cpy);
}
