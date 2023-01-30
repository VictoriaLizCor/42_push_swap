/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:17:58 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/30 17:36:28 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 	printf("*%p | %p\n", (void *)&*stack, st[0]);
// 	printf("%d", (void *)&*stack == st[0]);
// 	printf("%p\n", st[0]);
// 	printf("%p | %p\n", (void *)&*stack, st[0]);
// 	printf("%p | %p\n", (void *)&*stack, st[1]);
void	operations_on_stack_b(t_stack **stack_src, t_stack **stack_dst, int max_s_idx)
{
	if (!*stack_src || !(*stack_src)->next)
		return ;
	if ((*stack_src)->s_idx + 1 == (*stack_src)->next->s_idx)
		sb((*stack_src));
	else if ((*stack_src)->s_idx + 1 == (*stack_src)->previous->s_idx)
	{
		if ((*stack_src)->previous->s_idx == \
		find_max_value((*stack_src), &((*stack_src)->index)))
			rrb((&*stack_src));
		else
			rb((&*stack_src));
	}
	else
	{
		if ((*stack_src)->s_idx <= (max_s_idx / 2))
			pa(&*stack_src, &*stack_dst);
	}
}

void	operations_on_stack_a(t_stack **stack_src, t_stack **stack_dst, int max_s_idx)
{
	if ((*stack_src)->s_idx - 1 == (*stack_src)->next->s_idx)
		sa((*stack_src));
	else if ((*stack_src)->s_idx - 1 == (*stack_src)->previous->s_idx)
	{
		if ((*stack_src)->previous->s_idx == \
		find_min_value((*stack_src), &((*stack_src)->s_idx)))
			rra((&*stack_src));
		else
			ra((&*stack_src));
	}
	// else if ((*stack_src)->s_idx - 1 == (*stack_dst)->s_idx)
	// 	pa(&*stack_src, &*stack_dst);
	else
	{
		if ((*stack_src)->s_idx <= (max_s_idx / 2))
			pb(&*stack_src, &*stack_dst);
	}
}

void	check_first_element(t_stack **stack_src, t_stack **stack_dst, t_stacks_array st[2], int max_s_idx)
{
	if ((void *)&*stack_src == st[0].stack)
		operations_on_stack_a(&*stack_src, &*stack_dst, max_s_idx);
	if ((void *)&*stack_src == st[1].stack)
		operations_on_stack_b(&*stack_src, &*stack_dst, max_s_idx);
	show_stack(*stack_a, *stack_b);
	print_stack(*stack_a);
	print_stack(*stack_b);
}

// void	check_first_element(t_stack **stack_src, t_stack **stack_dst, t_stacks_array st[2], int max_s_idx)
// {
// 	if ((void *)&*stack_src == st[0].stack)
// 		operations_on_stack_a(&*stack_src, &*stack_dst, max_s_idx);
// 	if ((void *)&*stack_src == st[1].stack)
// 		operations_on_stack_b(&*stack_src, &*stack_dst, max_s_idx);
// }
// \find_max_value(*stack_a, &(*stack_a)->index) == max_elements
		// printf("max = %d\n", max_elements);
		// printf("inde≈ = %d\n", find_max_value(*stack_a, &(*stack_a)->index));
void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b, t_stacks_array st[2])
{
	int	i;
	int	max_s_idx;

	max_s_idx = find_max_value(*stack_a, &(*stack_a)->s_idx);
	i = 0;
	while (!check_sorted(*stack_a) && \
	i < 15)
	{
		check_first_element(&*stack_a, &*stack_b, st, max_s_idx);
		i++;
	}
	if (check_sorted(*stack_a))
		printf("OK\n");
	return ;
}
// {
// 		if ((*stack)->s_idx - 1 == (*stack)->next->s_idx)
// 	{
// 		if ((void *)&*stack == st[0].stack)
// 			sa((*stack));
// 		else if ((void *)&*stack == st[1].stack)
// 			sb((*stack));
// 	}
// 	else if ((*stack)->s_idx - 1 == (*stack)->previous->s_idx)
// 	{
// 		if ((void *)&*stack == st[0].stack)
// 		{
// 			if ((*stack)->previous->s_idx == \
// 			find_min_value((*stack), &((*stack)->index)))
// 				rra((&*stack));
// 			else
// 				ra((&*stack));
// 		}
// 		else if ((void *)&*stack == st[1].stack)
// 		{
// 			if ((*stack)->previous->s_idx == \
// 			find_min_value((*stack), &((*stack)->index)))
// 				rrb((&*stack));
// 			else
// 				rb((&*stack));
// 		}
// 	}
// 	else
// 		ra(&*stack);
// }

	// find_min_value(*stack_a, &(*stack_a)->s_idx) != size_stack_a &&

// void	sort_one(t_stack **stack)
// {
// 	return ;
// }

// void	sort_both(t_stack **stack_a, t_stack **stack_)
// {
// 	return ;
// }

// void	short_sort(t_stack *stack)
// {
// 	t_stack	*last;

// 	last = stack_last(stack);
// 	if (stack->value > stack->next->value)
// 		sa(stack);
// 	else if (stack->value > last->value)
// 		ra(&stack);
// }

	// while (1)
	// {
	// 	if (stack_a)
	// 		return ;
	// 	if (stack_b)
	// 		return ;
	// }

// void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b, t_stacks_array s_array[2], int size_stack_a)
// {
// 	int	i;
// // &stack_a->s_idx
// 	i = 0;
// 	*stack_b = NULL;
// 	while (!check_sorted(*(t_stack **)(s_array[0].stack)) && \
// 	find_min_value(*(t_stack **)(s_array[0].stack), &(*(t_stack **)(s_array[0].stack))->s_idx) != size_stack_a && \
// 	i++ < 10 )
// 	{
// 		check_first_element(&*stack_a, s_array);
// 		show_stack(*stack_a, *stack_b);
// 		print_stack(*stack_a);
// 	}
// 	if (check_sorted(*stack_a))
// 		printf("OK");
// 	return ;
// }
