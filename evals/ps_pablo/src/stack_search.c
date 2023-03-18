/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:05:09 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/01 11:02:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <limits.h>

//Function finds the minimum index element in a stack and returns the pointer.
t_node	*stack_index_min(t_stack *stack)
{
	int		tmpmin;
	t_node	*current;

	tmpmin = INT_MAX;
	current = stack->bottom;
	while (current != 0)
	{
		if (current->index < tmpmin)
			tmpmin = current->index;
		if (current->next == 0)
			break ;
		current = current->next;
	}
	while (current != 0)
	{
		if (current->index == tmpmin)
		{
			return (current);
		}
		current = current->prev;
	}
	return (0);
}

//Function finds the maximum index element in a stack and returns the pointer.
t_node	*stack_index_max(t_stack *stack)
{
	int		tmpmax;
	t_node	*current;

	tmpmax = INT_MIN;
	current = stack->bottom;
	while (current != 0)
	{
		if (current->index > tmpmax)
			tmpmax = current->index;
		if (current->next == 0)
			break ;
		current = current->next;
	}
	while (current != 0)
	{
		if (current->index == tmpmax)
		{
			return (current);
		}
		current = current->prev;
	}
	return (0);
}

//Function finds the minimum cost node in a stack and returns the pointer to it.
t_node	*stack_cost_min(t_stack *stack)
{
	int		tmpmin;
	t_node	*current;

	current = stack->bottom;
	tmpmin = INT_MAX;
	while (current != 0)
	{
		if ((absolute(current->cost_a) + absolute(current->cost_b)) < tmpmin)
			tmpmin = (absolute(current->cost_a) + absolute(current->cost_b));
		if (current->next == 0)
			break ;
		current = current->next;
	}
	while (current != 0)
	{
		if ((absolute(current->cost_a) + absolute(current->cost_b)) == tmpmin)
			return (current);
		if (current->prev == 0)
			break ;
		current = current->prev;
	}
	return (current);
}

//Function determines the minimum index present in the stack.
int	index_min(t_stack *stack)
{
	int		tmpmin;
	t_node	*current;

	current = stack->top;
	tmpmin = INT_MAX;
	while (current != 0)
	{
		if (current->index < tmpmin)
			tmpmin = current->index;
		if (current->prev == 0)
			break ;
		current = current->prev;
	}
	return (tmpmin);
}

//Function determines the maximum index present in the stack.
int	index_max(t_stack *stack)
{
	int		tmpmax;
	t_node	*current;

	current = stack->top;
	tmpmax = INT_MIN;
	while (current != 0)
	{
		if (current->index > tmpmax)
			tmpmax = current->index;
		if (current->prev == 0)
			break ;
		current = current->prev;
	}
	return (tmpmax);
}
