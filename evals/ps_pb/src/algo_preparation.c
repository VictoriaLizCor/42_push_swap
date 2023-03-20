/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_preparation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:53:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/08 14:57:10 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <limits.h>
#include <stdlib.h>

//Function assigns indices to stack elements, in order.
void	indexing(t_stack *stack)
{
	int		ix;
	int		tmpmin;
	t_node	*current;

	ix = 1;
	while (ix <= stack->nodecount)
	{
		current = stack->bottom;
		tmpmin = INT_MAX;
		while (current != 0)
		{
			if (current->index == 0 && current->value < tmpmin)
				tmpmin = current->value;
			if (current->next == 0)
				break ;
			current = current->next;
		}
		while (current != 0)
		{
			if (current->index == 0 && current->value == tmpmin)
				current->index = ix;
			current = current->prev;
		}
		ix++;
	}
}

//Function assigns the position of each node within the stack.
void	positioning(t_stack *stack)
{
	int		i;
	t_node	*current;

	current = stack->top;
	i = 0;
	while (current != 0)
	{
		current->pos = i;
		current = current->prev;
		i++;
	}
}

static void	targetassist(t_stack *stack_a, t_node *currentb)
{
	int		tpin;
	t_node	*currenta;

	tpin = INT_MAX;
	currenta = stack_a->bottom;
	while (currenta != 0)
	{		
		if (currentb->index < currenta->index && currenta->index < tpin)
		{
			tpin = currenta->index;
			currentb->pos_target = currenta->pos;
		}
		currenta = currenta->next;
	}
}

//Function calculates the current target position for stack b elements.
void	targeting(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*currentb;

	currentb = stack_b->bottom;
	while (currentb != 0)
	{
		if (currentb->index > stack_index_max(stack_a)->index)
			currentb->pos_target = stack_index_max(stack_a)->pos + 1;
		else if (currentb->index < stack_index_min(stack_a)->index)
			currentb->pos_target = stack_index_min(stack_a)->pos;
		else
			targetassist(stack_a, currentb);
		currentb = currentb->next;
	}
}

//Function works out the costs of moving each element to its intended location.
void	costing(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tempb;

	tempb = stack_b->bottom;
	while (tempb != 0)
	{
		tempb->cost_b = tempb->pos;
		if (tempb->pos > stack_size(stack_b) / 2)
			tempb->cost_b = -1 * (stack_size(stack_b) - tempb->pos);
		tempb->cost_a = tempb->pos_target;
		if (tempb->pos_target > stack_size(stack_a) / 2)
			tempb->cost_a = -1 * (stack_size(stack_a) - tempb->pos_target);
		if (tempb->next == 0)
			break ;
		tempb = tempb->next;
	}
	print_stack(stack_a);
	print_stack(stack_b);
}
