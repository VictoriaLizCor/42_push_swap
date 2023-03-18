// Tests for functions in algo_sort.c
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Test for initial_push_to_b
// run: cc algo_sort_main.c ../algo_sort.c ../stack_functions.c ../stack_operations.c ../node_functions.c ../operations_pushswap.c ../operations_rotate.c ../operations_reverse_rotate.c ../stack_special.c ../memory.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stacka;
	t_stack *stackb;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;

	stacka = stack_init(0, stacka);
	stackb = stack_init(1, stackb);
	node1 = node_init(100, node1);
	node2 = node_init(50, node2);
	node3 = node_init(150, node3);
	node4 = node_init(INT_MAX, node4);
	node5 = node_init(INT_MIN, node5);
	push(node1, stacka);
	push(node2, stacka);
	push(node3, stacka);
	push(node4, stacka);
	push(node5, stacka);
	printf("Stack A:\n");
	stack_display(stacka);
	printf("Stack nodecnt: %d\n", stacka->nodecount);
	printf("Init. push to B:\n");
	initial_push_to_b(stacka, stackb);
	printf("Stack A:\n");
	stack_display(stacka);
	printf("Stack B:\n");
	stack_display(stackb);
	free_stack(stacka);
	free_stack(stackb);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return (0);
}
//*/

/* Test for sort_three_a
// run: cc algo_sort_main.c ../algo_sort.c ../algo_preparation.c ../algo_execution.c ../stack_functions.c ../stack_operations.c ../node_functions.c ../operations_pushswap.c ../operations_rotate.c ../operations_reverse_rotate.c ../stack_special.c ../stack_search.c ../numbers.c ../memory.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack *stacka;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	stacka = stack_init(0, stacka);
	node1 = node_init(100, node1);
	node2 = node_init(150, node2);
	node3 = node_init(50, node3);
	push(node1, stacka);
	push(node2, stacka);
	push(node3, stacka);
	printf("Stack:\n");
	indexing(stacka);
	stack_display_full(stacka);
	printf("Stack nodecnt: %d\n", stacka->nodecount);
	printf("Sort 3:\n");
	sort_three_a(stacka);
	stack_display(stacka);
	free_stack(stacka);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
//*/
