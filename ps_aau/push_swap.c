/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:11:13 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 14:41:39 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Grading 5 points
** 3 numbers <= 3 moves,
** 5 numbers <= 12 moves,
** 100 numbers <= 700 moves
** 500 numbers <= 5500
**
** **** Rules
** non_repetive number to stack -> error if found
** +/- numbers allowed
** INT_MIN < numbers < INT_MAX
** Stack_A -> initialized with random numbers
** Stack_B -> empty
**
** **** Instructions
** sa  / sb  / ss
** ra  / rb  / rr
** rra / rrb / rrr
** pa 	/ pb
**
** In case of error, it must display "Error" followed by a ’\n’ on the standard
** error. Errors include for example: some
** arguments aren’t integers, some arguments
** are bigger than an integer and/or there are
** duplicates
*/

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

static void	fill_stack(t_stack **stack_a, char **argv)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!new_node)
		*stack_a = NULL;
	new_node->value = (int)(ft_atoi(*argv));
	if (!(*stack_a))
		*stack_a = new_node;
	else
	{
		last = stack_last(*stack_a);
		last->next = new_node;
		new_node->previous = last;
		if (!(*(argv + 1)))
			(*stack_a)->previous = new_node;
	}
	update_idx_stack(*stack_a);
}

static void	push_swap(char **argv)
{
	static t_stack	*stack_b;
	static t_stack	*stack_a;

	while (*(argv))
		fill_stack(&stack_a, &(*argv++));
	check_repeated(stack_a);
	sort_index(stack_a);
	sorting_algorithm(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit(0);
	check_integers(++argv);
	push_swap(argv);
	exit(EXIT_SUCCESS);
}
