/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:11:13 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/08 15:28:36 by lilizarr         ###   ########.fr       */
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

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

static void	fill_stack(t_stack **stack_a, char **argv)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)ft_calloc (sizeof(t_stack), 1);
	if (!new_node)
		*stack_a = NULL;
	new_node->value = ft_atoi(*argv);
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
	update_idx_stack_a(*stack_a);
}

static void	push_swap(char **argv)
{
	static t_stack	*stack_b;
	static t_stack	*stack_a;

	while (*(argv))
		fill_stack(&stack_a, &(*argv++));
	check_repeated(stack_a);
	sort_index(stack_a);
	// show_stack(stack_a, stack_b);
	print_stack(stack_a);
	sorting_algorithm(&stack_a, &stack_b);
	// show_stack(stack_a, stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
}
	// printf("array content | \t\t%p\n", *(t_stack **)(s_array[0].stack));
	// 	printf("array content | \t\t%p\n", t_stacks_array st[2]);
	// pb(&stack_a, &stack_b);
	// show_stack(stack_a, stack_b);
	// print_stack(stack_a);
	// print_stack(stack_b);
	// pb(&stack_a, &stack_b);
	// show_stack(stack_a, stack_b);
	// print_stack(stack_a);
	// print_stack(stack_b);

	// printf("min value idx = %d \n", find_min_value(stack_a, &stack_a->s_idx));
	// printf("max value idx = %d \n", find_max_value(stack_a, &stack_a->s_idx));
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
	ft_printf("\n size = %d\t\n|", argc);
	check_integers(++argv);
	push_swap(argv);
	ft_printf("\n size = %d\t./push_swap", argc - 1);
	while (*argv)
	{
		ft_printf(" %s ", *argv);
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