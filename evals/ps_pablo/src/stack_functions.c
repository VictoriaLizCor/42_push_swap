/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:35:46 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/03 15:53:13 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdlib.h>

//Funcion initialises a stack with only its id.
t_stack	*stack_init(int id, t_stack *stack)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("Malloc error!\n");
		exit(0);
	}
	stack->id = id;
	stack->nodecount = 0;
	stack->bottom = 0;
	stack->top = 0;
	return (stack);
}

//Function fills a stack with numbers from a valid character array.
void	stack_fill(char **charr, t_stack *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	while (charr[i] != 0)
		i++;
	i--;
	while (i >= 0)
	{
		temp = node_init(ft_atoi(charr[i]), temp);
		push(temp, stack);
		free(temp);
		i--;
	}
}

//Function pops a stack completely.
void	stack_pop(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->top != 0)
	{
		pop(stack);
		i++;
	}
}

//Function determines the number of elements in a stack.
int	stack_size(t_stack *stack)
{
	int		i;
	t_node	*current;

	current = stack->bottom;
	if (current == 0)
		return (0);
	i = 1;
	while (current->next != 0)
	{
		current = current->next;
		i++;
	}
	return (i);
}

//Function determines whether the stack is sorted.
int	stack_issorted(t_stack *stacka)
{
	t_node	*node;

	if (stacka->nodecount < 2)
		return (1);
	node = stacka->top;
	while (node != 0)
	{
		if (node->prev == 0)
			break ;
		if (node->value > node->prev->value)
			return (0);
		node = node->prev;
	}
	return (1);
}
