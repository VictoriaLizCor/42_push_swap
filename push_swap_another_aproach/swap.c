/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:56 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/13 14:21:36 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack	*stack)
{
	int		tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->s_idx;
	stack->s_idx = stack->next->s_idx;
	stack->next->s_idx = tmp;
}

void	sa(t_stack *stack)
{
	swap(stack);
	ft_printf("sa\n");
	update_idx_stack_a(stack);
	update_weight(stack);
}

void	sb(t_stack *stack)
{
	swap(stack);
	ft_printf("sb\n");
	update_idx_stack_a(stack);
	update_weight(stack);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	update_idx_stack_a(stack_a);
	update_weight(stack_a);
	update_idx_stack_a(stack_b);
	update_weight(stack_b);
}

// void	do_swap(t_stack *stack_a, t_stack *stack_b)
// {
	
// }

// void	swap_exe(t_stacks_array s_array[2], int i)
// {
// 	swap(*(t_stack **)s_array[i].stack);
// 	ft_printf("s");
// 	if (i == 0 || i == 1)
// 		ft_printf("%c\n", s_array[i].c_type);
// 	else
// 		ft_printf("s\n");
// }

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