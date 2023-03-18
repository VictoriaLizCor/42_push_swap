/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:56:21 by iczarnie          #+#    #+#             */
/*   Updated: 2022/05/13 14:56:21 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->a_score = -1;
	node->a_rev_score = -1;
	node->b_score = -1;
	node->a_rev_score = -1;
	node->rank = -1;
	node->next = NULL;
	return (node);
}

void	add_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!new || !stack)
		return ;
	if (*stack != NULL)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	else
	{
		*stack = new;
	}
}

void	create_stack(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!new || !stack)
		return ;
	if (*stack != NULL)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	else
	{
		*stack = new;
	}
}

int	stack_length(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
