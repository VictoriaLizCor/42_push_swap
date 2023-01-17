/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/17 11:54:47 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	update_weight(stack);
}

void	sa(t_stack *stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}


// void	swap(t_stack **stack)
// {
// 	t_stack	*new_head;
// 	t_stack	*new_tail;

// 	if (!(*stack) || !(*stack)->next)
// 		return ;
// 	new_tail = (*stack);
// 	new_head = stack_last(*stack);
// 	new_head->previous->next = new_tail;
// 	new_head->previous = NULL;
// 	new_head->next = (*stack)->next;
// 	(*stack) = new_head;
// 	new_tail->next = NULL; 
// 	printf("new_head %p -> next = %p\n", new_head, new_head->next);
// 	printf("new_tail %p -> next = %p\n", new_tail, new_tail->next);
// 	printf("stack %p -> next = %p\n", (*stack), (*stack)->next);
// 	new_head->head = 1;
// 	new_head->tail = 0;
// 	new_tail->head = 0;
// 	new_head->tail = 1;
// 	//update_weight((*stack));
// }