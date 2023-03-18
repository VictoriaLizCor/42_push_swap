/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker_pushswap.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:28:36 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/03 15:33:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker.h"
#include <stdlib.h>

//Function pushes the top element of stack b to stack a. Suppresses message.
void	chk_push_a(t_stack *st_a, t_stack *st_b)
{
	t_node	*node;

	if (st_b->top == 0)
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		ft_printf("Malloc error!\n");
		exit(0);
	}
	node_inherit(node, st_b->top);
	push(node, st_a);
	pop(st_b);
	free(node);
}

//Function pushes the top element of stack a to stack b. Suppresses message.
void	chk_push_b(t_stack *st_a, t_stack *st_b)
{
	t_node	*node;

	if (st_a->top == 0)
		return ;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		ft_printf("Malloc error!\n");
		exit(0);
	}
	node_inherit(node, st_a->top);
	push(node, st_b);
	pop(st_a);
	free(node);
}

//Function swaps the first two elements on a stack a. Suppresses message.
void	chk_swap_a(t_stack *st_a)
{
	if (st_a->top == 0 || st_a->top->prev == 0)
		return ;
	swap(st_a);
}

//Function swaps the first two elements on a stack b. Suppresses message.
void	chk_swap_b(t_stack *st_b)
{
	if (st_b->top == 0 || st_b->top->prev == 0)
		return ;
	swap(st_b);
}

//Function swaps the first two elements of each of two stacks a and b. No msg.
void	chk_swap_ab(t_stack *st_a, t_stack *st_b)
{
	if (st_a->top == 0 || st_b->top == 0)
		return ;
	if (st_a->top->prev == 0 || st_b->top->prev == 0)
		return ;
	swap(st_a);
	swap(st_b);
}
