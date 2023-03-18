// Tests for functions in operations_pushswap.c
#include "test.h"
#include <stdlib.h>
#include <stdio.h>

/* Test for push_a and push_b
// run: cc ops_pushswap_main.c ../operations_pushswap.c
int	main(void)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Push a---\n")
	push_a(stack_a, stack_b);
	printf("---Push b---"\n);
	push_b(stack_a, stack_b);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	push(500, stack_a);
	push(250, stack_b);
	printf("Post-Fill Stack \"a\":\n");
	stack_display(stack_a);
	printf("Post-Fill Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Push a---\n");
	push_a(stack_a, stack_b);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Push b---\n");
	push_b(stack_a, stack_b);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
//*/

/* Test for swap_a swap_b and swap_ab
int	main(void)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Swap a---");
	swap_a(stack_a);
	printf("---Swap b---");
	swap_b(stack_b);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	push(500, stack_a);
	push(250, stack_b);
	printf("Post-One-Fill Stack \"a\":\n");
	stack_display(stack_a);
	printf("Post-One-Fill Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Swap a---\n");
	swap_a(stack_a);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Swap b---\n");
	swap_b(stack_b);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	push(125, stack_a);
	push(375, stack_b);
	push(555, stack_a);
	push(333, stack_b);
	printf("Post-Fill Stack \"a\":\n");
	stack_display(stack_a);
	printf("Post-Fill Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Swap a---\n");
	swap_a(stack_a);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Swap b---\n");
	swap_b(stack_b);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	printf("---Swap both---\n");
	swap_ab(stack_a, stack_b);
	printf("Stack \"a\":\n");
	stack_display(stack_a);
	printf("Stack \"b\":\n");
	stack_display(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
//*/
