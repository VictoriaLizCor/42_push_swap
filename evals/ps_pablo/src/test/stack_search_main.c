// Tests for functions in stack_search.c
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

/* Test for stack_index_min
// run: cc stack_search_main.c ../stack_search.c ../stack_operations.c ../stack_functions.c ../stack_special.c ../algo_preparation.c ../operations_pushswap.c ../operations_reverse_rotate.c ../operations_rotate.c ../algo_execution.c ../node_functions.c ../numbers.c ../memory.c test.c ../../libft/libft.a
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
	node2 = node_init(450, node2);
	node3 = node_init(50, node3);
	node4 = node_init(150, node4);
	node5 = node_init(350, node5);
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	push(node4, stack);
	push(node5, stack);
	indexing(stack);
	pop_bottom(stack);
	pop_bottom(stack);
	positioning(stack);
	printf("Stack:\n");
	stack_display_full(stack);
	printf("Min. Index:\n");
	node_display(stack_index_min(stack));
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return (0);
}
//*/

/* Test for stack_cost_min
// run: cc stack_search_main.c ../stack_search.c ../stack_operations.c ../stack_functions.c ../stack_special.c ../operations_pushswap.c ../operations_reverse_rotate.c ../operations_rotate.c ../node_functions.c ../numbers.c ../memory.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;

	stack = stack_init(0, stack);
	node1 = node_init(10, node1);
	node2 = node_init(20, node2);
	node3 = node_init(30, node3);
	node1->cost_a = 1;
	node1->cost_b = 0;
	node2->cost_a = 2;
	node2->cost_b = 1;
	node3->cost_a = 0;
	node3->cost_b = 1;
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	printf("Stack:\n");
	stack_display(stack);
	printf("Min cost:\n");
	node_display(stack_cost_min(stack));
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
//*/

/* Test for stack_issorted
// run: cc stack_search_main.c ../stack_search.c ../stack_operations.c ../stack_functions.c ../stack_special.c ../algo_preparation.c ../operations_pushswap.c ../operations_reverse_rotate.c ../operations_rotate.c ../algo_execution.c ../node_functions.c ../numbers.c ../memory.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;
	t_node	*minnode;

	stack = stack_init(0, stack);
	node1 = node_init(350, node1);
	node2 = node_init(250, node2);
	node3 = node_init(150, node3);
	node4 = node_init(100, node4);
	node5 = node_init(50, node5);
	minnode = (t_node *)malloc(sizeof(t_node));
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	push(node4, stack);
	push(node5, stack);
	indexing(stack);
	positioning(stack);
	printf("Stack:\n");
	stack_display_full(stack);
	printf("Stack is sorted: %d\n", stack_issorted(stack));
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return (0);
}
//*/
