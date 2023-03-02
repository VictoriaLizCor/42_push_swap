/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/02/27 11:01:34 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->s_idx + 1 != stack->next->s_idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_inverse(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->s_idx - 1 != stack->next->s_idx)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	check_sorted_inverse_value(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->s_idx < stack->next->s_idx)
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
