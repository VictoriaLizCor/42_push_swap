/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:20:34 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/31 20:10:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdlib.h>

//Function pushes (new) data to the top of the stack.
void	push(t_node *node, t_stack *stack)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	node_inherit(new, node);
	if (stack->top == (void *) 0)
	{
		new->prev = 0;
		new->next = 0;
		stack->bottom = new;
	}
	else
	{
		new->prev = stack->top;
		new->next = 0;
		stack->top->next = new;
	}
	stack->nodecount++;
	stack->top = new;
}

//Function pops (removes) the top element of the stack.
void	pop(t_stack	*stack)
{
	t_node	*node;

	node = stack->top;
	if (node == 0)
	{
		return ;
	}
	else if ((node->next == 0 && node->prev == 0) || \
				stack->top == stack->bottom)
	{
		stack->top = 0;
		stack->bottom = 0;
		free(node);
	}
	else
	{
		stack->top->next = 0;
		stack->top->prev->next = 0;
		stack->top = node->prev;
		free(node);
	}
	stack->nodecount--;
}

//Function swaps the top two elements of the stack.
void	swap(t_stack *stack)
{
	t_node	*temptop;
	t_node	*temptopprev;

	if (stack->bottom == stack->top)
		return ;
	temptop = (t_node *)malloc(sizeof(t_node));
	temptopprev = (t_node *)malloc(sizeof(t_node));
	node_inherit(temptop, stack->top);
	node_inherit(temptopprev, stack->top->prev);
	pop(stack);
	pop(stack);
	push(temptop, stack);
	push(temptopprev, stack);
	free(temptop);
	free(temptopprev);
}

//Function moves all elements of the stack up by one, top becomes bottom.
void	rotate(t_stack *stack)
{
	t_node	*temptop;

	temptop = (t_node *)malloc(sizeof(t_node));
	node_inherit(temptop, stack->top);
	pop(stack);
	push_bottom(temptop, stack);
	free(temptop);
}

//Function moves all elements of the stack down by one, bottom becomes top.
void	reverse_rotate(t_stack *stack)
{
	t_node	*tempbottom;

	tempbottom = (t_node *)malloc(sizeof(t_node));
	node_inherit(tempbottom, stack->bottom);
	pop_bottom(stack);
	push(tempbottom, stack);
	free(tempbottom);
}
