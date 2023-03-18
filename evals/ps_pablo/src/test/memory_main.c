// Tests for the functions in memory.c
#include "test.h"
#include <stdlib.h>

/* Test for free_charr
// run: cc memory_main.c ../memory.c ../../libft/libft.a
int	main(void)
{
	char	str[] = "6543 6654 222 1211 33";
	char	**charr;

	charr = ft_split(str, ' ');
	free_charr(charr, ft_nwrds(str, ' '));
	return (0);
}
//*/

/* Test for free_split
// run: cc memory_main.c ../memory.c ../../libft/libft.a
int	main(void)
{
	char	str[] = "6543 6654 222 1211 33";
	char	**split;

	split = ft_split(str, ' ');
	free_split(split);
	return (0);
}
//*/

/* Test for free_stack
// run: cc memory_main.c ../memory.c ../stack_operations.c ../stack_special.c ../stack_functions.c ../node_functions.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack	*stack;
	t_node *node1;
	t_node *node2;
	t_node *node3;
	t_node *node4;
	t_node *node5;

	stack = stack_init(0, stack);
	node1 = node_init(10, node1);
	node2 = node_init(20, node2);
	node3 = node_init(30, node3);
	node4 = node_init(40, node4);
	node5 = node_init(50, node5);
	push(node1, stack);
	push_bottom(node2, stack);
	stack_display_full(stack);
	pop_bottom(stack);
	pop(stack);
	stack_display_full(stack);
	push_bottom(node3, stack);
	push(node4, stack);
	push(node5, stack);
	stack_display_full(stack);
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
}
//*/