// Tests for functions in algo_preparation.c
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

/* Test for indexing
// run: cc algo_prep_main.c ../algo_preparation.c ../memory.c test.c
int	main(void)
{
	t_stack *stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;

	stack = (t_stack *)malloc(sizeof(t_stack));
	node1 = (t_node *)malloc(sizeof(t_node));
	node2 = (t_node *)malloc(sizeof(t_node));
	node3 = (t_node *)malloc(sizeof(t_node));
	node4 = (t_node *)malloc(sizeof(t_node));
	node5 = (t_node *)malloc(sizeof(t_node));
	node_init(100, node1);
	node_init(50, node2);
	node_init(150, node3);
	node_init(INT_MAX, node4);
	node_init(INT_MIN, node5);
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	push(node4, stack);
	push(node5, stack);
	printf("Stack:\n");
	stack_display_full(stack);
	printf("Stack nodecnt: %d\n", stack->nodecount);
	indexing(stack);
	stack_display_full(stack);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	return (0);
}
//*/

/* Test for positioning
// run: cc algo_prep_main.c ../algo_preparation.c ../memory.c test.c
int main(void)
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
	positioning(stacka);
	stack_display_full(stacka);
	printf("Stack nodecnt: %d\n", stacka->nodecount);
	free_stack(stacka);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
//*/

/* Test for targeting
// run: cc algo_prep_main.c ../algo_preparation.c ../algo_sort.c ../algo_execution.c ../stack_functions.c ../stack_operations.c ../node_functions.c ../operations_pushswap.c ../operations_rotate.c ../operations_reverse_rotate.c ../stack_special.c ../stack_search.c ../numbers.c ../memory.c test.c ../../libft/libft.a
int main(void)
{
	t_stack *stacka = 0;
	t_stack *stackb = 0;
	t_node	*node1 = 0;
	t_node	*node2 = 0;
	t_node	*node3 = 0;
	t_node	*node4 = 0;
	t_node	*node5 = 0;
	t_node	*node6 = 0;
	t_node	*node7 = 0;
	t_node	*node8 = 0;

	stacka = stack_init(0, stacka);
	stackb = stack_init(1, stackb);
	node1 = node_init(100, node1);
	node2 = node_init(50, node2);
	node3 = node_init(150, node3);
	node4 = node_init(350, node4);
	node5 = node_init(80, node5);
	node6 = node_init(450, node3);
	node7 = node_init(750, node4);
	node8 = node_init(20, node5);
	push(node1, stacka);
	push(node2, stacka);
	push(node3, stacka);
	push(node4, stacka);
	push(node5, stacka);
	push(node6, stacka);
	push(node7, stacka);
	push(node8, stacka);
	indexing(stacka);
	initial_push_to_b(stacka, stackb);
	sort_three_a(stacka);
	positioning(stacka);
	positioning(stackb);
	printf("After indexing, push to B, sorting, positioning:\n");
	printf("Stack A:\n");
	stack_display_full(stacka);
	printf("Stack B:\n");
	stack_display_full(stackb);
	targeting(stacka, stackb);
	positioning(stacka);
	positioning(stackb);
	printf("After Targeting:\n");
	printf("Stack A:\n");
	stack_display_full(stacka);
	printf("Stack B:\n");
	stack_display_full(stackb);
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

/* Test for costing
// run: cc algo_prep_main.c ../algo_preparation.c ../memory.c test.c
int main(void)
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
	node4 = node_init(350, node4);
	node5 = node_init(20, node5);
	push(node1, stacka);
	push(node2, stacka);
	push(node3, stacka);
	push(node4, stacka);
	push(node5, stacka);
	indexing(stacka);
	initial_push_to_b(stacka, stackb);
	positioning(stacka);
	positioning(stackb);
	targeting(stacka, stackb);
	printf("After indexing, push to B, positioning, targeting:\n");
	printf("Stack A:\n");
	stack_display_full(stacka);
	printf("Stack B:\n");
	stack_display_full(stackb);
	costing(stacka, stackb);
	printf("After Costing:\n");
	printf("Stack A:\n");
	stack_display_full(stacka);
	printf("Stack B:\n");
	stack_display_full(stackb);
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

/* Test for optimisation_execution
// run: cc algo_prep_main.c ../algo_preparation.c ../memory.c test.c
int main(void)
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
	node4 = node_init(350, node4);
	node5 = node_init(20, node5);
	push(node1, stacka);
	push(node2, stacka);
	push(node3, stacka);
	push(node4, stacka);
	push(node5, stacka);
	indexing(stacka);
	initial_push_to_b(stacka, stackb);
	sort_three_a(stacka);
	positioning(stacka);
	positioning(stackb);
	targeting(stacka, stackb);
	costing(stacka, stackb);
	printf("After indexing, pushing, sorting, positioning, targeting, costing:\n");
	printf("Stack A:\n");
	stack_display_full(stacka);
	printf("Stack B:\n");
	stack_display_full(stackb);
	optimisation_execution(stacka, stackb);
	printf("Post-Optimisation:\n");
	printf("Stack A:\n");
	stack_display_full(stacka);
	printf("Stack B:\n");
	stack_display_full(stackb);
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
