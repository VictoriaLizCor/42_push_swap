/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosing_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:29:04 by iczarnie          #+#    #+#             */
/*   Updated: 2022/05/04 12:29:04 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	final_score2(t_node *stack, int *operation_type_key,
	int result, int top_rscore)
{
	if (stack->b_rev_score > top_rscore)
		top_rscore = stack->b_rev_score;
	if (result > top_rscore)
	{
		result = top_rscore;
		if (stack->b_rev_score > stack->a_rev_score)
			*operation_type_key = 3;
		else
			*operation_type_key = 4;
	}
	if (stack->b_score + stack->a_rev_score < result)
	{
		result = stack->b_score + stack->a_rev_score;
		*operation_type_key = 5;
	}
	if (stack->b_rev_score + stack->a_score < result)
	{
		result = stack->b_rev_score + stack->a_score;
		*operation_type_key = 6;
	}
	return (result);
}

int	final_score(t_node *stack, int *operation_type_key)
{
	int	result;
	int	top_rscore;

	result = stack->a_score;
	*operation_type_key = 1;
	if (stack->b_score >= stack->a_score)
	{
		result = stack->b_score;
		*operation_type_key = 2;
	}
	top_rscore = stack->a_rev_score;
	result = final_score2(stack, operation_type_key, result, top_rscore);
	return (result);
}

t_node	*chose_move(t_node *stack, int *operation_type_key)
{
	t_node	*best;
	int		score;
	int		rank;
	int		operation_key;

	operation_key = *operation_type_key;
	best = stack;
	score = final_score(stack, operation_type_key);
	rank = stack->rank;
	while (stack)
	{
		if (final_score(stack, operation_type_key) < score
			|| (final_score(stack, operation_type_key)
				== score && stack->rank >= rank))
		{
			score = final_score(stack, operation_type_key);
			rank = stack->rank;
			operation_key = *operation_type_key;
		}
		stack = stack->next;
	}
	*operation_type_key = operation_key;
	while (best->rank != rank)
		best = best->next;
	return (best);
}

void	execute_operations2(t_node **stack_a, t_node **stack_b, t_node *node,
	int *operation_type_key)
{
	if (*operation_type_key == 4)
	{
		while (node->b_rev_score-- > 0 && node->a_rev_score--)
			do_rrr(stack_a, stack_b);
		while (node->a_rev_score-- > 0)
			do_rrab(stack_a, 1, 'a');
	}
	if (*operation_type_key == 5)
	{
		while (node->b_score-- > 0)
			do_rab(stack_b, 1, 'b');
		while (node->a_rev_score-- > 0)
			do_rrab(stack_a, 1, 'a');
	}
	if (*operation_type_key == 6)
	{
		while (node->b_rev_score-- > 0)
			do_rrab(stack_b, 1, 'b');
		while (node->a_score-- > 0)
			do_rab(stack_a, 1, 'a');
	}
}

void	execute_operations(t_node **stack_a, t_node **stack_b, t_node *node,
	int *operation_type_key)
{
	if (*operation_type_key == 1)
	{
		while (node->b_score-- > 0 && node->a_score--)
			do_rr(stack_a, stack_b);
		while (node->a_score-- > 0)
			do_rab(stack_a, 1, 'a');
	}
	if (*operation_type_key == 2)
	{
		while (node->a_score-- > 0 && node->b_score--)
			do_rr(stack_a, stack_b);
		while (node->b_score-- > 0)
			do_rab(stack_b, 1, 'b');
	}
	if (*operation_type_key == 3)
	{
		while (node->a_rev_score-- > 0 && node->b_rev_score--)
			do_rrr(stack_a, stack_b);
		while (node->b_rev_score-- > 0)
			do_rrab(stack_b, 1, 'b');
	}
	execute_operations2(stack_a, stack_b, node, operation_type_key);
	do_pa(stack_a, stack_b, 1);
}
