/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:20:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/08 10:46:02 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "./libft/libft.h"
#include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				pos_target;
	int				cost_a;
	int				cost_b;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int		id;
	int		nodecount;
	t_node	*bottom;
	t_node	*top;
}			t_stack;

// INPUT CLEANERS
//Function converts a character array to one compatible with ft_split output.
char	**splitise(char **argv, int argc);

// INDIVIDUAL VALIDATORS
//Function checks whether a character is a numeric one.
int		isnumeric(char ch);
//Function checks whether a string contains a valid signed numeric declaration.
int		isvalidnum(char *str);

// ARRAY VALIDATORS
//Function checks that arguments of a string array are valid.
int		argcheck(char **charr);
//Function checks that array members contain only digits and numeric symbols.
int		isarrnumeric(char **charr);
//Function checks that all the array submembers represent only integers.
int		isarrint(char **charr);
//Function checks that there are no duplicate numbers within the main array.
int		isarrdup(char **charr);
//Function checks whether array members are ordered.
int		isarrsorted(char **charr);

// NODE FUNCTIONS
//Function initialises a node with only its value.
t_node	*node_init(int val, t_node *node);
//Function copies values from one node to another.
void	node_inherit(t_node *dest, t_node *source);

// STACK FUNCTIONS
//Funcion initialises a stack with only its id.
t_stack	*stack_init(int id, t_stack *stack);
//Function fills a stack with numbers from a valid character array.
void	stack_fill(char **charr, t_stack *stack);
//Function determines the number of elements in a stack.
int		stack_size(t_stack *stack);
//Function pops a stack completely.
void	stack_pop(t_stack *stack);

// STACK SEARCHING
//Function finds the minimum value in a stack and returns the node's pointer.
t_node	*stack_index_min(t_stack *stack);
//Function finds the maximum index element in a stack and returns the pointer.
t_node	*stack_index_max(t_stack *stack);
//Function finds the minimum cost node in a stack and returns the pointer to it.
t_node	*stack_cost_min(t_stack *stack);
//Function determines the minimum index present in the stack.
int		index_min(t_stack *stack);
//Function determines the maximum index present in the stack.
int		index_max(t_stack *stack);
//Function determines whether the stack is sorted.
int		stack_issorted(t_stack *stacka);

// SORTING ALGORITHM PREPARATION
//Function assigns indices to stack elements, in order.
void	indexing(t_stack *stack);
//Function assigns the position of each node.
void	positioning(t_stack *stack);
//Function calculates the current target position for stack b elements.
void	targeting(t_stack *stack_a, t_stack *stack_b);
//Function works out the costs of moving each element to its intended location.
void	costing(t_stack *stack_a, t_stack *stack_b);

// SORTING ALGORITHM STEPS
//Function pushes all elements to stack b except 3.
void	initial_push_to_b(t_stack *stack_a, t_stack *stack_b);
//Function sorts 3 elements. (Very defined sorting case). Intended for stack a.
void	sort_three_a(t_stack *stack_a);
//Function rotates stack A moving it closer to full order (stack b empty).
void	rotation_a(t_stack *stacka);

// ALGORITHM EXECUTION
//Function works out cheapest node and performs the optimised operations.
void	optimisation_execution(t_stack *stack_a, t_stack *stack_b);
//Function performs stack operations until costs are exhausted. Cheapest node.
void	perform_operations(t_stack *stack_a, t_stack *stack_b);

// ALGORITHM OPERATIONS/INSTRUCTIONS
//Function pushes the top element of stack b to stack a.
void	push_a(t_stack *st_a, t_stack *st_b);
//Function pushes the top element of stack a to stack b.
void	push_b(t_stack *st_a, t_stack *st_b);
//Function swaps the first two elements on a stack a.
void	swap_a(t_stack *st_a);
//Function swaps the first two elements on a stack b.
void	swap_b(t_stack *st_b);
//Function swaps the first two elements of each of two stacks a and b.
void	swap_ab(t_stack *st_a, t_stack *st_b);
//Function moves all elements of a stack a up by one.
void	rotate_a(t_stack *st_a);
//Function moves all elements of a stack b up by one.
void	rotate_b(t_stack *st_b);
//Function moves all elements of two stacks a and b up by one.
void	rotate_ab(t_stack *st_a, t_stack *st_b);
//Function moves all elements of a stack a down by one.
void	rev_rotate_a(t_stack *st_a);
//Function moves all elements of a stack b down by one.
void	rev_rotate_b(t_stack *st_b);
//Function moves all elements of two stacks a and b down by one.
void	rev_rotate_ab(t_stack *st_a, t_stack *st_b);

// STACK OPERATIONS
//Function pushes (new) data to the top of the stack.
void	push(t_node *node, t_stack *stack);
//Function pops (removes) the top element of the stack.
void	pop(t_stack	*stack);
//Function swaps the top two elements of the stack.
void	swap(t_stack *stack);
//Function moves all elements of the stack up by one, top becomes bottom.
void	rotate(t_stack *stack);
//Function moves all elements of the stack down by one, bottom becomes top.
void	reverse_rotate(t_stack *stack);

// STACK SPECIAL OPERATIONS
//Function pushes a new item to the bottom of the DLL stack.
void	push_bottom(t_node *node, t_stack *stack);
//Function pops the bottom element of the DLL stack.
void	pop_bottom(t_stack *stack);
//Function pops any node in a DLL stack.
void	pop_any(t_node *node, t_stack *stack);

// NUMBER FUNCTIONS
//Function turns a string to a long integer type.
long	ft_atol(char *str);
//Function returns the absolute value of an integer.
int		absolute(int num);

// MEMORY HANDLING
//Function frees a 2D char array, given its size.
void	free_charr(char **charr, int charrsz);
//Function frees a 2D char array made from ft_split.
void	free_split(char **charr);
//Function frees the memory allocated to a stack.
void	free_stack(t_stack *stack);

// ERROR HANDLING
//Function displays error message on standard error.
int		display_error(void);

void	stack_display_full(t_stack *stack);
void	print_stack(t_stack *list);
#endif