/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:27:09 by iczarnie          #+#    #+#             */
/*   Updated: 2022/04/24 20:27:09 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	two_arguments(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		do_rab(stack, 1, 'a');
	free_stack(stack);
	exit(0);
}

void	initiate_stack_a(int argc, char **argv, t_node **stack)
{
	int		x;

	x = 0;
	argv++;
	while (++x < argc)
	{
		create_stack(stack, new_node(ft_atoi(*argv)));
		argv++;
	}
}

int	stack_sorted(t_node *stack)
{
	t_node	*last_element;

	last_element = last(stack);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	if (stack && stack->value > last_element->value)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		return (0);
	if (error_check(argc, argv) == 1)
		error();
	initiate_stack_a(argc, argv, &stack_a);
	if (duplicate_check(&stack_a) == 1)
		error();
	if (argc == 3)
		two_arguments(&stack_a);
	if (stack_sorted(stack_a) == 0)
		stack_b = to_b(&stack_a);
	while (stack_b)
		move_to_a(&stack_a, &stack_b);
	final_sort(&stack_a);
	free_stack(&stack_a);
	return (0);
}
