// Test for functions in stack_special.c
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

/* Test for push_bottom
// run: cc stack_special_main.c ../stack_special.c ../stack_operations.c ../stack_functions.c ../node_functions.c ../memory.c ./test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;

	stack = stack_init(0, stack);
	node1 = node_init(100, node1);
	node2 = node_init(50, node2);
	node3 = node_init(150, node3);
	node4 = node_init(25, node4);
	node5 = node_init(250, node5);
	push_bottom(node1, stack);
	push_bottom(node2, stack);
	push_bottom(node3, stack);
	push(node4, stack);
	push(node5, stack);
	printf("Stack:\n");
	stack_display_full(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return (0);
}
//*/

/* Test for pop_bottom
// run: cc stack_special_main.c ../stack_special.c ../stack_operations.c ../stack_functions.c ../node_functions.c ../memory.c ./test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;

	stack = stack_init(0, stack);
	node1 = node_init(100, node1);
	node2 = node_init(50, node2);
	node3 = node_init(150, node3);
	node4 = node_init(25, node4);
	node5 = node_init(250, node5);
	push_bottom(node1, stack);
	push_bottom(node2, stack);
	push_bottom(node3, stack);
	push(node4, stack);
	push(node5, stack);
	printf("Stack:\n");
	stack_display_full(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	//Pop
	pop_bottom(stack);
	printf("*Pop bottom*:\n");
	stack_display_full(stack);
	//Pop
	pop_bottom(stack);
	printf("*Pop bottom*:\n");
	stack_display_full(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	//Pop
	pop_bottom(stack);
	printf("*Pop bottom*:\n");
	stack_display_full(stack);
	//Pop
	pop(stack);
	printf("*Pop*:\n");
	stack_display_full(stack);
	printf("stack->top: %p\n", stack->top);
	printf("stack->bottom: %p\n", stack->bottom);
	//free(stack->top);
	//Pop
	//pop_bottom(stack);
	pop(stack);
	printf("*Pop Empty bottom*:\n");
	stack_display_full(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	printf("Done Popping.\n");
	//free(stack->top);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return (0);
}
//*/

/* Test for pop_any
// run: cc stack_special_main.c ../stack_special.c ../stack_operations.c ../stack_functions.c ../node_functions.c ../memory.c ./test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*select;

	stack = (t_stack *)malloc(sizeof(t_stack));
	node1 = (t_node *)malloc(sizeof(t_node));
	node2 = (t_node *)malloc(sizeof(t_node));
	node3 = (t_node *)malloc(sizeof(t_node));
	node4 = (t_node *)malloc(sizeof(t_node));
	node_init(100, node1);
	node_init(50, node2);
	node_init(150, node3);
	node_init(250, node4);
	push_bottom(node1, stack);
	push_bottom(node2, stack);
	push_bottom(node3, stack);
	push_bottom(node4, stack);
	printf("Stack:\n");
	stack_display(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	select = stack->top->prev;
	pop_any(select, stack);
	printf("Pop second to top:\n");
	stack_display(stack);
	select = stack->top;
	pop_any(select, stack);
	printf("Pop top:\n");
	stack_display(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	select = stack->bottom;
	pop_any(select, stack);
	printf("Pop bottom:\n");
	stack_display(stack);
	printf("Stack node count: %d\n", stack->nodecount);
	select = stack->bottom;
	pop_any(select, stack);
	printf("Pop last:\n");
	stack_display(stack);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return (0);
}
//*/
