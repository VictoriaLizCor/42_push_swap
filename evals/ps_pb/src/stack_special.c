/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:19:31 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/31 20:09:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdlib.h>

//Function pushes a new item to the bottom of the DLL stack.
void	push_bottom(t_node *node, t_stack *stack)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	node_inherit(new, node);
	if (stack->bottom == 0)
	{
		new->prev = 0;
		new->next = 0;
		stack->top = new;
	}
	else
	{
		new->prev = 0;
		new->next = stack->bottom;
		stack->bottom->prev = new;
	}
	stack->nodecount++;
	stack->bottom = new;
}

//Function pops the bottom element of the DLL stack.
void	pop_bottom(t_stack *stack)
{
	t_node	*node;
	t_node	*current;

	node = stack->bottom;
	if (node == 0)
		return ;
	else if (node->next == 0 && node->prev == 0)
	{
		stack->top = 0;
		stack->bottom = 0;
		free(node);
	}
	else
	{
		current = stack->bottom->next;
		stack->bottom->prev = 0;
		current->prev = 0;
		stack->bottom = node->next;
		free(node);
	}
	stack->nodecount--;
}

//Function pops any node in a DLL stack.
void	pop_any(t_node *node, t_stack *stack)
{
	if (node == 0)
		return ;
	if (node->prev == 0)
		stack->bottom = node->next;
	if (node->next == 0)
		stack->top = node->prev;
	if (node->next != 0)
		node->next->prev = node->prev;
	if (node->prev != 0)
		node->prev->next = node->next;
	free(node);
	stack->nodecount--;
	return ;
}
