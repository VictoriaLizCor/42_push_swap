// Tests for functions in stack_filling.c
#include "test.h"
#include <stdlib.h>
#include <stdio.h>

/* Test for fill_stack
// run: cc stack_func_main.c ../memory.c ../stack_filling.c test.c ../stack_operations.c ../../libft/libft.a
int	main(void)
{
	char	**charr;
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	charr = ft_split("1243 2124 23222 443 2131", ' ');
	fill_stack(charr, stack);
	stack_display(stack);
	free_split(charr);
	free_stack(stack);
	return (0);
}
//*/

/* Test for stack_size
// run: cc stack_func_main.c ../stack_functions.c ../stack_operations.c ../stack_special.c ../node_functions.c ../memory.c ./test.c ../../libft/libft.a
int	main(void)
{
	t_stack	*stack;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;

	node1 = node_init(50, node1);
	node2 = node_init(10, node2);	
	node3 = node_init(20, node3);
	node4 = node_init(55, node4);
	stack = stack_init(0, stack);
	push(node1, stack);
	push(node2, stack);
	push(node3, stack);
	push(node4, stack);
	stack_display(stack);
	printf("Size: %d\n", stack_size(stack));
	free_stack(stack);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return (0);
}
//*/

/* Test for stack_pop
// run: cc stack_func_main.c ../stack_functions.c ../stack_operations.c ../memory.c ./test.c ../../libft/libft.a
int	main(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	push(5, stack);
	push(15, stack);
	push(25, stack);
	stack_display(stack);
	stack_pop(stack);
	printf("*Stack Pop*\n");
	stack_display(stack);
	free_stack(stack);
	return (0);
}
//*/
