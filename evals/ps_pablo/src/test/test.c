// Functions for carrying out tests
#include "test.h"
#include <stdio.h>

//Function to display a stack from top to bottom.
void	stack_display(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (node == 0)
	{
		printf("Empty\n");
		return ;
	}
	printf("-----Top-----\n");
	while (node != (void *) 0)
	{
		printf("Value: %d\n", node->value);
		node = node->prev;
	}
}

//Function to display a node and its data.
void	node_display(t_node *node)
{
	printf("Node:\n");
	printf("Value: %d\n", node->value);
	printf("Index: %d\n", node->index);
	printf("Position: %d\n", node->pos);
	printf("Target Pos: %d\n", node->pos_target);
	printf("Cost to rot a: %d\n", node->cost_a);
	printf("Cost to rot b: %d\n", node->cost_b);
}

//Function prints a whole stack with its nodes data.
void	stack_display_full(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (node == 0)
	{
		printf("Empty\n");
		return ;
	}
	printf("------------------------Top------------------------\n");
	printf("Val. | Ind. | Pos. | Pos. Tgt. | Cost A | Cost B| next | prev\n");
	while (node != 0)
	{
		printf("%5d  %5d  %5d     %5d     %5d    %5d  %5p  %5p\n", node->value, \
				node->index, node->pos, node->pos_target, node->cost_a, \
				node->cost_b, node->next, node->prev);
		node = node->prev;
	}
}
