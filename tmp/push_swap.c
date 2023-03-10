/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:11:13 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/27 16:29:22 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//seq -1000 2000 | sort -R | tail -n 1000 | tr '\n' ' '
#include "./lib/libft/libft.h"
/*
3 numbers <= 3 moves,
5 numbers <= 12 moves, 
100 numbers <= 700 moves
500 numbers <= 5500
*/

/* Rules
non_repetive number to stack -> error if found
+/- numbers allowed
INT_MIN < numbers < INT_MAX
Stack_A -> initialized with random numbers
Stack -> empty
sort in ascending order 
*/

/* Instructions 
sa  / sb  / ss
ra  / rb  / rr
rra / rrb / rrr
pa 	/ pb
*/

int	main(void)
{
	ft_printf("HOLA\n");
	return (0);
}

// static void	push_swap(int argc, char **argv)
// {
// 	static t_stack	*stack_b;
// 	static t_stack	*stack_a;
// 	// t_stacks_array	s_array[2];
// 	void *ptr;
// 	void *value;
// 	int i;
// 	i=0;

// 	// s_array[0].stack = &stack_a;
// 	// s_array[0].c_type = ('a');
// 	// s_array[1].stack = &stack_b;
// 	// s_array[1].c_type = ('b');
// 	while (*(argv))
// 		fill_stack(&stack_a, argc--, &(*argv++));
// 	check_repeated(stack_a);
// 	show_stack(stack_a, stack_b);
// 	sort_index(stack_a);
// 	show_stack(stack_a, stack_b);
// 		while (stack_a)
// 	{
// 		ptr = stack_a;
// 		printf("%ld \n", (long)(sizeof(t_stack)));
// 		value = (&stack_a->weight);
// 		printf("ptr %p \n", ptr);
// 		printf("%d \n", (*(int *)(ptr + (value - ptr))));
// 		printf("%ld \n", sizeof(*(int *)(ptr + (value - ptr))));
// 		printf("value %p \n", value);
// 		printf("stack %p \n", ((void *)stack_a) + (value - ptr));
// 		printf("stack val %ld \n", ((*(int *)stack_a) + (value - ptr)));
// 		// printf("s_dsx = %p\n", (int *)&(stack_a->s_idx));
// 		printf("value = %d\n", stack_a->value);
// 		printf("s_idx = %d\n", stack_a->s_idx);
// 		printf("index = %d\n", stack_a->index);
// 		printf("weight = %d\n", stack_a->weight);
// 		printf("head = %d\n", stack_a->head);
// 		printf("tail = %d\n", stack_a->tail);
// 		printf("prev = %p \n", stack_a->previous);
// 		printf("next = %p \n", stack_a->next);
// 		printf("\n \t\t stack+a + i\t\t &stack+a + i \t ptr + 1\n ");
// 		while (i < 80)
// 		{
// 			printf(" \t\t%d %p", i,((void *)stack_a + i));
// 			printf(" \t\t%d", *(int *)((void *)(stack_a) + i));
// 			printf("\t %p \t %d\n ", ptr + i, 
// 			(*(int *)(ptr + i)));
// 			// (&stack_a + i), ptr + i);
// 			i++;
// 			// i = i + 4;
// 		}
// 		stack_a = stack_a->next;
// 	}
// }