// Tests for the functions in algo_execution.c
#include "test.h"

/* Test for perform_operations
// run: cc -g algo_exec_main.c ../algo_execution.c ../algo_preparation.c ../algo_sort.c ../stack_operations.c ../stack_functions.c ../stack_special.c ../stack_search.c ../node_functions.c ../operations_pushswap.c ../operations_rotate.c ../operations_reverse_rotate.c ../numbers.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack	*stacka;
	t_stack *stackb;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;

	stacka = stack_init(0, stacka);
	stackb = stack_init(0, stackb);
	node1 = node_init(10, node1);
	node2 = node_init(20, node2);
	node3 = node_init(40, node3);
	node4 = node_init(30, node4);
	push(node1, stacka);
	push(node2, stacka);
	push(node3, stacka);
	push(node4, stacka);
	stack_display(stacka);
	indexing(stacka);
	initial_push_to_b(stacka, stackb);
	stack_display(stacka);
	stack_display(stackb);
	sort_three_a(stacka);
	positioning(stacka);
	positioning(stackb);
	targeting(stacka, stackb);
	costing(stacka, stackb);
	perform_operations(stacka, stackb);
	positioning(stacka);
	rotation_a(stacka);
	stack_display(stacka);
	return (0);
}
//*/
