/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pushswap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:28:36 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/21 03:41:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stdlib.h>

//Function pushes the top element of stack b to stack a.
void	push_a(t_stack *st_a, t_stack *st_b)
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
	ft_printf("pa\n");
	free(node);
}

//Function pushes the top element of stack a to stack b.
void	push_b(t_stack *st_a, t_stack *st_b)
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
	ft_printf("pb\n");
	free(node);
}

//Function swaps the first two elements on a stack a.
void	swap_a(t_stack *st_a)
{
	if (st_a->top == 0 || st_a->top->prev == 0)
		return ;
	swap(st_a);
	ft_printf("sa\n");
}

//Function swaps the first two elements on a stack b.
void	swap_b(t_stack *st_b)
{
	if (st_b->top == 0 || st_b->top->prev == 0)
		return ;
	swap(st_b);
	ft_printf("sb\n");
}

//Function swaps the first two elements of each of two stacks a and b.
void	swap_ab(t_stack *st_a, t_stack *st_b)
{
	if (st_a->top == 0 || st_b->top == 0)
		return ;
	if (st_a->top->prev == 0 || st_b->top->prev == 0)
		return ;
	swap(st_a);
	swap(st_b);
	ft_printf("ss\n");
}
