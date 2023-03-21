/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:51:35 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 10:01:46 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	while (stack)
	{
		if (stack->s_idx == 0)
			break ;
		stack = stack->next;
	}
	min = stack->value;
	while (stack)
	{
		if (stack->s_idx == 0)
		{
			if (min > stack->value)
				min = stack->value;
		}
		stack = stack->next;
	}
	return (min);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}

// void test_allocation(t_stack *stack_a)
// {
// 	int						i;
// 	void					*ptr;
// 	void					*value;

// 	while (stack_a)
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
	// int					i;
	// int					*ptr;
	// int					*value;

	// while (stack_a)
	// {
	// 	i = 0;
	// 	ptr = (void *)stack_a;
	// 	printf("%ld \n", (long)(sizeof(t_stack)));
	// 	value = &stack_a->weight;
	// 	printf("%ld \n", (value - ptr));
	// 	printf("%p \n", ptr);
	// 	printf("%p \n", value);
	// ft_printf("\nMax val : %d\n", 