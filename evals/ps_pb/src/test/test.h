// Header for testing functions.

#ifndef TEST_H
# define TEST_H
# include "../../pushswap.h"

//Function to display a stack from top to bottom.
void	stack_display(t_stack *stack);
//Function to display a node and its data.
void	node_display(t_node *node);
//Function prints a whole stack with its nodes data.
void	stack_display_full(t_stack *stack);
#endif
