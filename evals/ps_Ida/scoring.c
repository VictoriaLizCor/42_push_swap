/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:40:33 by iczarnie          #+#    #+#             */
/*   Updated: 2022/05/03 14:40:33 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*last(t_node *stack)
{
	if (stack != NULL)
	{
		while (stack->next != NULL)
		{
			stack = stack->next;
		}
	}
	return (stack);
}

void	score_b(t_node *stack_b)
{
	int	length;
	int	i;

	length = stack_length(stack_b);
	i = 0;
	while (stack_b)
	{
		stack_b->b_score = i;
		stack_b->b_rev_score = length - i;
		stack_b = stack_b->next;
		i++;
	}
}

void	score_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*copy;
	int		i;
	int		previous;
	int		length;

	copy = stack_a;
	length = stack_length(stack_a);
	while (stack_b)
	{
		stack_a = copy;
		i = 0;
		previous = last(stack_a)->value;
		while (stack_a)
		{
			if (previous < stack_b->value && stack_a->value > stack_b->value)
			{
				stack_b->a_score = i;
				stack_b->a_rev_score = length - i;
			}
			i++;
			previous = stack_a->value;
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
}
