/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 14:42:46 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_stack *stack, void *value)
{
	int		min;
	int		diff;

	diff = (value - (void *)stack);
	min = *(int *)((void *)stack + diff);
	while (stack)
	{
		if (min > *(int *)((void *)stack + diff))
			min = *(int *)((void *)stack + diff);
		stack = stack->next;
	}
	return (min);
}

int	find_max_value(t_stack *stack, void *value)
{
	int		max;
	int		diff;

	diff = (value - (void *)stack);
	max = *(int *)((void *)stack + diff);
	while (stack)
	{
		if (max < *(int *)((void *)stack + diff))
			max = *(int *)((void *)stack + diff);
		stack = stack->next;
	}
	return (max);
}

static int	check_sorted_idx(t_stack *head)
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

static int	find_min(t_stack *stack)
{
	int	min;

	while (stack)
	{
		if (stack->s_idx == 0)
			break ;
		stack = stack->next;
	}
	min = stack->value;
	while (stack)
	{
		if (stack->s_idx == 0)
		{
			if (min > stack->value)
				min = stack->value;
		}
		stack = stack->next;
	}
	return (min);
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
