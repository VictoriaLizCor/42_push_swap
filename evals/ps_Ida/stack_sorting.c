/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:15:42 by iczarnie          #+#    #+#             */
/*   Updated: 2022/05/13 16:15:42 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*to_b(t_node **stack)
{
	t_node	*stack_b;
	int		min;
	int		max;
	int		med;
	int		length;

	length = stack_length(*stack);
	stack_b = NULL;
	min_max_med(stack, &min, &max, &med);
	while (length > 3)
	{
		if ((*stack)->value == min
			|| (*stack)->value == max || (*stack)->value == med)
			do_rab(stack, 1, 'a');
		else
		{
			do_pb(stack, &stack_b, 1);
			length--;
		}
	}
	sort_three(stack);
	return (stack_b);
}

void	final_sort(t_node **stack)
{
	t_node	*node;
	int		min;
	int		i;
	int		length;
	int		*array;

	array = create_and_sort_array(stack);
	min = array[0];
	node = *stack;
	i = 0;
	while (node->value != min)
	{
		node = node->next;
		i++;
	}
	length = stack_length(*stack);
	if (i <= length - i)
		while (i--)
			do_rab(stack, 1, 'a');
	else
		while (i++ < length)
			do_rrab(stack, 1, 'a');
	free(array);
}

void	move_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*winner;
	int		ttype;

	score_b(*stack_b);
	score_a(*stack_a, *stack_b);
	winner = chose_move(*stack_b, &ttype);
	execute_operations(stack_a, stack_b, winner, &ttype);
}

void	score(t_node **stack_a, t_node **stack_b)
{
	score_b(*stack_b);
	score_a(*stack_a, *stack_b);
}
