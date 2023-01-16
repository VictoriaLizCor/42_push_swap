/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:11:13 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/16 17:22:11 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//seq -1000 2000 | sort -R | tail -n 1000 | tr '\n' ' '
#include "push_swap.h"
/***** Grading 5 points
3 numbers <= 3 moves,
5 numbers <= 12 moves, 
100 numbers <= 700 moves
500 numbers <= 5500
*/

/****** Rules
non_repetive number to stack -> error if found
+/- numbers allowed
INT_MIN < numbers < INT_MAX
Stack_A -> initialized with random numbers
Stack -> empty
sort in ascending order 
*/

/****** Instructions 
sa  / sb  / ss
ra  / rb  / rr
rra / rrb / rrr
pa 	/ pb
*/

// static void	free_node_stack(void **list)
// {
// 	t_stack	*tmp;
// 	t_stack	*to_erase;
// 	int		i;

// 	i = 0;
// 	to_erase = *list;
// 	tmp = to_erase->next;
// 	free(to_erase);
// 	*list = tmp;
// }

static void	fill_stack(t_stack **stack_a, int argc, char *argv)
{
	t_stack	*new_node;

	new_node = (t_stack *)ft_calloc (sizeof(t_stack), 1);
	if (!new_node)
		*stack_a = NULL;
	new_node->value = ft_atoi(argv);
	new_node->index = argc;
	new_node->weight = new_node->index - new_node->value;
	if (!(*stack_a))
	{
		*stack_a = new_node;
		new_node->head = 1;
		new_node->tail = 1;
	}
	else
	{
		new_node->next = *stack_a;
		new_node->head = 1;
		(*stack_a)->previous = new_node;
		(*stack_a)->head = 0;
		*stack_a = new_node;
	}
}

int	check_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(int argc, char **argv)
{
	static t_stack		*stack_a;
	static t_stack		*stack_b;

	while (*(argv))
		fill_stack(&stack_a, --argc, *argv++);
	show_stack(stack_a, stack_b);
	print_stack(stack_a);
	printf("\nsorted(%d)\n", check_sorted(stack_a));
	rotate(stack_a);
	show_stack(stack_a, stack_b);
	print_stack(stack_a);
}
//free((void *)stack_a);
// free_node_stack((void *)stack_a);

/* 
In case of error, it must display "Error" followed by a ’\n’ on the standard 
error. Errors include for example: some 
arguments aren’t integers, some arguments 
are bigger than an integer and/or there are 
duplicates.
*/
int	main(int argc, char **argv)
{
	if (argc < 2)
		exit(0);
	// if(argc >= 2)
	ft_printf("\n size = %d\t|", argc);
	check_integers(++argv);
	push_swap(--argc, argv);
	ft_printf("\n size = %d\t|", argc);
	while (*argv)
	{
		ft_printf(" %s |", *argv);
		argv++;
	}
	ft_printf("\n\n");
	exit(EXIT_SUCCESS);
}


/*
  min			max
  ||			||	
  max			min
-------		  -------
stack-a		  stack-b

*/

/*
	pb(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	show_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	show_stack(stack_a, stack_b);
	pa(&stack_b, &stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	show_stack(stack_a, stack_b);
	pa(&stack_b, &stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	show_stack(stack_a, stack_b);
*/