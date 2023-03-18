//Tests for the functions in stack_operations.c
#include "test.h"
#include <stdlib.h>
#include <stdio.h>

/* Test for push
// run: cc stack_ops_main.c ../stack_functions.c ../stack_operations.c ../node_functions.c ../stack_special.c ../memory.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	stack = stack_init(0, stack);
	node1 = node_init(5, node1);
	node2 = node_init(25, node1);
	node3 = node_init(125, node1);
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	printf("Stack:\n");
	stack_display(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
//*/

/* Test for pop
// run: cc stack_ops_main.c ../stack_operations.c ../stack_functions.c ../node_functions.c ../stack_special.c ../memory.c ../input.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;
	t_node	*node6;

	stack = (t_stack *)malloc(sizeof(t_stack));
	node1 = (t_node *)malloc(sizeof(t_node));
	node2 = (t_node *)malloc(sizeof(t_node));
	node3 = (t_node *)malloc(sizeof(t_node));
	node4 = (t_node *)malloc(sizeof(t_node));
	node5 = (t_node *)malloc(sizeof(t_node));
	node6 = (t_node *)malloc(sizeof(t_node));
	node_init(5, node1);
	node_init(25, node2);
	node_init(125, node3);
	node_init(53, node4);
	node_init(225, node5);
	node_init(15, node6);
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	push(node4, stack);
	push(node5, stack);
	push(node6, stack);
	printf("Stack:\n");
	stack_display_full(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	pop(stack);
	printf("*Pop*:\n");
	stack_display_full(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	pop(stack);
	printf("*Pop*:\n");
	stack_display_full(stack);
	pop(stack);
	printf("*Pop*:\n");
	stack_display_full(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	pop(stack);
	printf("*Pop*:\n");
	pop(stack);
	printf("*Pop*:\n");
	stack_display_full(stack);
	pop(stack);
	printf("*Pop Empty*:\n");
	stack_display_full(stack);
	printf("Done Popping.\n");
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);
	return (0);
}
//*/

/* Test for swap
// run: cc stack_ops_main.c ../stack_operations.c ../memory.c ./test.c ../stack_functions.c ../stack_special.c ../../libft/libft.a
int	main(void)
{
	t_stack	*stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	stack = (t_stack *)malloc(sizeof(t_stack));
	node1 = (t_node *)malloc(sizeof(t_node));
	node2 = (t_node *)malloc(sizeof(t_node));
	node3 = (t_node *)malloc(sizeof(t_node));
	node_init(100, node1);
	node_init(50, node2);
	node_init(150, node3);
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	printf("Stack:\n");
	stack_display(stack);
	swap(stack);
	printf("Swapped:\n");
	stack_display(stack);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
//*/

/* Test for rotate
// run: cc stack_ops_main.c ../stack_operations.c ../memory.c ./test.c ../stack_functions.c ../stack_special.c ../../libft/libft.a
int	main(void)
{
	t_stack	*stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;

	stack = (t_stack *)malloc(sizeof(t_stack));
	node1 = (t_node *)malloc(sizeof(t_node));
	node2 = (t_node *)malloc(sizeof(t_node));
	node3 = (t_node *)malloc(sizeof(t_node));
	node4 = (t_node *)malloc(sizeof(t_node));
	node_init(105, node1);
	node_init(210, node2);
	node_init(555, node3);
	node_init(333, node4);
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	push(node4, stack);
	stack_display(stack);
	rotate(stack);
	printf("Rotated:\n");
	stack_display(stack);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return (0);
}
//*/

/* Test for reverse_rotate
// run: cc stack_ops_main.c ../stack_operations.c ../memory.c ./test.c ../stack_functions.c ../stack_special.c ../../libft/libft.a
int	main(void)
{
	t_stack	*stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;

	stack = (t_stack *)malloc(sizeof(t_stack));
	node1 = (t_node *)malloc(sizeof(t_node));
	node2 = (t_node *)malloc(sizeof(t_node));
	node3 = (t_node *)malloc(sizeof(t_node));
	node4 = (t_node *)malloc(sizeof(t_node));
	node_init(105, node1);
	node_init(210, node2);
	node_init(555, node3);
	node_init(333, node4);
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	push(node4, stack);
	stack_display(stack);
	reverse_rotate(stack);
	printf("Rev. Rotated:\n");
	stack_display(stack);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return (0);
}
//*/
