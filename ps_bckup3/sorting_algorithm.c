/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:17:58 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/02 15:38:09 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_stack_b(t_stack **stack_b, t_stack **stack_a, int max_s_idx)
{
	ft_printf("op_b: \t");
	ft_printf("\n ** %d\n", (*stack_b)->s_idx);
	if ((*stack_a)->s_idx - 1 == (*stack_b)->s_idx && \
	check_sorted(*stack_a))
		pa(&*stack_b, &*stack_a);
	else if ((*stack_b)->s_idx < (max_s_idx / 2) + 1)
	{
		if ((*stack_b)->s_idx + 1 == (*stack_b)->previous->s_idx)
			rb((&*stack_b));
		else if ((*stack_b)->s_idx - 1 == (*stack_b)->next->s_idx)
			sb((*stack_b));
		else
			rrb((&*stack_b));
	}
	else if (*stack_b && (*stack_b)->next)
	{
		if ((*stack_b)->s_idx + 1 == (*stack_b)->next->s_idx)
			sb((*stack_b));
		else if ((*stack_b)->s_idx == \
		find_min_value((*stack_b), &((*stack_b)->s_idx)))
			rb(&*stack_b);
		else if ((*stack_b)->previous->s_idx == \
		find_max_value((*stack_b), &((*stack_b)->s_idx)))
			rb((&*stack_b));
		else if ((*stack_b)->s_idx + 1 == (*stack_b)->previous->s_idx)
			rrb((&*stack_b));
		else if ((*stack_b)->s_idx < \
		find_max_value((*stack_b), &((*stack_b)->index)))
			rb((&*stack_b));
		else
		{
			if (max_s_idx > 3 && (*stack_b)->s_idx > (max_s_idx / 2) + 1 && \
			!check_sorted(*stack_a))
				pa(&*stack_b, &*stack_a);
		}
	}
}

void	operations_stack_a(t_stack **stack_a, t_stack **stack_b, int max_s_idx)
{
	ft_printf("op_a: \t");
	if (check_sorted(*stack_a) && (*stack_b))
		pa(&*stack_b, &*stack_a);
	else if (find_min_value((*stack_a), &((*stack_a)->index)) > 3 && \
	(*stack_a)->s_idx >= (max_s_idx / 2) + 1)
	{
		if ((*stack_a)->s_idx + 1 == (*stack_a)->previous->s_idx)
			rra((&*stack_a));
		else if ((*stack_a)->s_idx - 1 == (*stack_a)->next->s_idx)
			sa((*stack_a));
		else
			ra((&*stack_a));
	}
	else if ((*stack_a)->s_idx - 1 == (*stack_a)->next->s_idx)
		sa((*stack_a));
	else if ((*stack_a)->s_idx + 1 == (*stack_a)->previous->s_idx || \
	(*stack_a)->previous->s_idx == \
	find_min_value((*stack_a), &((*stack_a)->s_idx)))
		rra((&*stack_a));
	else if ((*stack_a)->s_idx - 1 == (*stack_a)->previous->s_idx)
		ra((&*stack_a));
	else if ((*stack_a)->s_idx >= (max_s_idx / 2) + 1)
		ra((&*stack_a));
	else if (max_s_idx > 3 && (*stack_a)->s_idx < \
	(max_s_idx / 2) + 1 && !check_sorted(*stack_a))
		pb(&*stack_a, &*stack_b);
}

// void	middle_sort(t_stack **stack_a, t_stack **stack_b, int mid)
// {
// 	if ((*stack_a)->s_idx >= mid && (*stack_a)->next->s_idx >= mid)
// 	{
// 		if ((*stack_a)->s_idx > (*stack_a)->next->s_idx)
// 		{
// 			if ((*stack_a)->s_idx + 1 != (*stack_a)->next->s_idx && \
// 			(*stack_a)->s_idx - 1 != (*stack_a)->previous->s_idx)
// 				sa(*stack_a);
// 			print_stack(*stack_a);
// 		}
// 	}
// 	if ((*stack_b) && (*stack_b)->next)
// 	{
// 		// if (check_sorted_inverse_value(*stack_b))
// 		// {
// 		// 	ft_printf("\nsorted_b\n");
// 		// 	return ;
// 		// }
// 		// if ((*stack_b)->s_idx - 1 != (*stack_b)->next->s_idx && \
// 		// 	(*stack_b)->s_idx + 1 != (*stack_b)->previous->s_idx)
// 		// 		sb(*stack_b);
// 		// else
// 		// 	rb((&*stack_b));
// 		// print_stack(*stack_b);
// 		ft_printf("_mid = %d", (find_max_value(*stack_b, &(*stack_b)->index) / 2 ));
// 		if ((*stack_b)->s_idx < (find_max_value(*stack_b, &(*stack_b)->index) / 2 ))
// 			rb((&*stack_b));
// 		else if ((*stack_b)->s_idx < (*stack_b)->next->s_idx)
// 			sb(*stack_b);
// 		print_stack(*stack_b);
// 	}
// }

// t_stack	*find_target(t_stack *stack, int type, int size, int max_s_idx)
// {
// 	t_stack	*tmp1;
// 	t_stack	*tmp2;
// 	int		check;
// 	int		target_s_idx;

// 	tmp1 = stack;
// 	check = 0;
// 	if (type >= 0)
// 		target_s_idx = find_min_value(stack, &(stack->s_idx));
// 	else
// 		target_s_idx = find_max_value(stack, &(stack->s_idx));
// 	while (tmp1->s_idx != target_s_idx)
// 	{
// 		tmp1 = tmp1->next;
// 		ft_printf("target_s_idx = %d || %d \n", target_s_idx, tmp1->s_idx);
// 		if (check == 0 && (tmp1->s_idx < (max_s_idx / 2 ) + 1))
// 		{
// 			tmp2 = tmp1;
// 			printf("found\n");
// 			check = 1;
// 		}
// 	}
// 	printf("tmp1 = %p || tmp2 =%p \n size - tmp1->index + 1= %d \t\t|| tmp2->index = %d\n", tmp1, tmp2, size - tmp1->index, tmp2->index - 1);
// 	if ((size - tmp1->index + 1) >= tmp2->index - 1)
// 		return (tmp2);
// 	else
// 		return (tmp1);
// }

void	middle_sort(t_stack **stack_a, t_stack **stack_b, int mid)
{
	if ((*stack_a)->s_idx >= mid && (*stack_a)->next->s_idx >= mid)
	{
		if ((*stack_a)->s_idx > (*stack_a)->next->s_idx)
		{
			sa(*stack_a);
			print_stack(*stack_a);
		}
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		ft_printf("_mid = %d\n", (find_max_value(*stack_b, &(*stack_b)->index) / 2 ));
		if ((*stack_b)->s_idx <= \
		(find_max_value(*stack_b, &(*stack_b)->index) / 2 ))
			rb((&*stack_b));
		else if ((*stack_b)->s_idx < (*stack_b)->next->s_idx)
			sb(*stack_b);
		print_stack(*stack_b);
	}
}

t_stack	*find_target_s_idx(t_stack *stack, int type)
{
	t_stack	*tmp1;
	int		target_s_idx;

	tmp1 = stack;
	if (type >= 0)
		target_s_idx = find_min_value(stack, &(stack->s_idx));
	else
		target_s_idx = find_max_value(stack, &(stack->s_idx));
	while (tmp1->s_idx != target_s_idx)
		tmp1 = tmp1->next;
	return (tmp1);
}

t_stack	*find_target_closer(t_stack *stack, int type, int mid)
{
	t_stack	*tmp_target;
	t_stack	*target;
	int		size;

	size = find_max_value(stack, &(stack->index));
	tmp_target = stack;
	target = find_target_s_idx(stack, 1);
	if (type >= 0)
	{
		while (tmp_target->s_idx >= mid)
			tmp_target = tmp_target->next;
	}
	else
	{
		while (tmp_target->s_idx > mid)
			tmp_target = tmp_target->next;
	}
	ft_printf("size = %d || \ttarget = %d || %d \n", size, target->index, tmp_target->index);
	ft_printf("target = %p || tmp =%p \n size - target->index + 1= %d \t\t|| tmp->index-1 = %d\n", target, tmp_target, size + 1 - target->index, tmp_target->index - 1);
	if (((size + 1) - target->index) >= tmp_target->index - 1)
		return (tmp_target);
	else
		return (target);
}

t_stack *last_ordered_element(t_stack *stack)
{
	t_stack *tmp_last;

	tmp_last = stack;
	
	while (tmp_last->next != NULL)
	{
		if (tmp_last->s_idx + 1 != tmp_last->next->s_idx)
			break;
		tmp_last = tmp_last->next;
	}
	return (tmp_last);
	
}

void divide_stack(t_stack **stack_a, t_stack **stack_b, int size, int limit)
{
	t_stack	*target;

	ft_printf("----- divide stack\n");
	if ((*stack_a)->s_idx >= limit)
	{
		if ((*stack_a)->s_idx +1 == (*stack_a)->next->s_idx)
		{
			sa(*stack_a);
			print_stack(*stack_a);
		}
	}
	if ((*stack_a)->s_idx >= limit)
	{
		target = find_target_closer((*stack_a), 1, limit);
		ft_printf("a -> %p \t\t\t stack_a = %p || \t size /2 =  %d\n", target, *stack_a,  size / 2 + 1);
		if (target->index >= size / 2 + 1)
			rra(&*stack_a);
		else
			ra(&*stack_a);
	}
	else
		pb(&*stack_a, &*stack_b);
	print_stack(*stack_a);
	print_stack(*stack_b);
	// if (*stack_b && (*stack_b)->next != NULL)
	// {
	// 	target = find_target_closer((*stack_b), -1, max_s_idx);
	// 	ft_printf("b -> %p \t\t\t stack_b = %p\n", target, *stack_b);
	// }
	ft_printf("----- end\n");
}

void	divide_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*target;

	while (!check_sorted(*stack_a) && size > 3)
	{
		target = last_ordered_element(*stack_a);
		ft_printf("taa -> %p \t\t\t|| \t index_tar =  %d || \t index_tar =  %d\n", target, target->index, target->s_idx);
		if (target->index >= 2 && (target->s_idx > find_max_s_idx(*stack_a) -  2))
		{
			if (target->index >= size / 2 + 1)
			{
				while (target != (*stack_a)->previous)
					rra(&*stack_a);
			}
			else
			{
				while (target != (*stack_a)->previous)
					ra(&*stack_a);
			}
			print_stack(*stack_a);
			return ;
		}
		divide_stack(&*stack_a, &*stack_b, size, find_max_s_idx(*stack_a) -  2);
		//middle_sort(&*stack_a, &*stack_b, find_max_s_idx(*stack_a) -  2);
		size = find_max_value((*stack_a), &((*stack_a)->index));
	}
}

void	sort_3(t_stack **stack)
{
	t_stack	*target;

	target = find_target_s_idx(*stack, 1);
	ft_printf("sort_3 \n || target->idx =  %d\n", target->index);
	if ((*stack)->s_idx - 1 == (*stack)->next->s_idx)
			sa(*stack);
	else
	{
		if (target->index == 3 || target->index == 1)
			rra(&*stack);
		else
			ra(&*stack);
	}
}
//./push_swap 3 4 2 1
void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	max_s_idx;
	int	size;

	max_s_idx = find_max_value(*stack_a, &(*stack_a)->s_idx);
	size = max_s_idx;
	i = 1;
	while ((!check_sorted(*stack_a)) && i++ < 4)
	{
		if (size > 3)
		{
			//operations_stack_a(&*stack_a, &*stack_b, max_s_idx);
			divide_sort(&*stack_a, &*stack_b, max_s_idx);
		}
		else
			sort_3(&*stack_a);
		print_stack(*stack_a);
		// else
		// {
		// 	if (!check_sorted(*stack_a))
		// 		operations_stack_a(&*stack_a, &*stack_b, max_s_idx);
		// 	if (*stack_b != NULL)
		// 		operations_stack_b(&*stack_b, &*stack_a, max_s_idx);
		// }
		size = find_max_value(*stack_a, &(*stack_a)->index);
		ft_printf("size = %d || max_sdx = %d\n", size, max_s_idx);
	}
	if (check_sorted(*stack_a))
		ft_printf("OK\n");
}
// void divide_stack(t_stack **stack_a, t_stack **stack_b, int size, int mid)
// {
// 	t_stack	*target;

// 	ft_printf("----- divide stack\n");
// 	target = last_ordered_section_element(*stack_a);
// 	ft_printf("taa -> %p \t\t\t|| \t index_tar =  %d || \t index_tar =  %d\n", target, target->index, target->s_idx);
// 	if (target->index >= 2 && (target->s_idx > find_max_s_idx(*stack_a) -  2))
// 	{
// 		if (target->index >= size / 2 + 1)
// 		{
// 			while (target != (*stack_a)->previous)
// 				rra(&*stack_a);			
// 		}
// 		else
// 		{
// 			while (target != *stack_a)
// 				ra(&*stack_a);
	
// 		}
// 		print_stack(*stack_a);
// 		return ;
// 	}
// 	if ((*stack_a)->s_idx >= mid)
// 	{
// 		target = find_target_closer((*stack_a), 1, mid);
// 		ft_printf("a -> %p \t\t\t stack_a = %p || \t size /2 =  %d\n", target, *stack_a,  size / 2 + 1);
// 		if (target->index >= size / 2 + 1)
// 			rra(&*stack_a);
// 		else
// 			ra(&*stack_a);
// 	}
// 	else
// 		pb(&*stack_a, &*stack_b);
// 	print_stack(*stack_a);
// 	print_stack(*stack_b);
// 	// if (*stack_b && (*stack_b)->next != NULL)
// 	// {
// 	// 	target = find_target_closer((*stack_b), -1, max_s_idx);
// 	// 	ft_printf("b -> %p \t\t\t stack_b = %p\n", target, *stack_b);
// 	// }
// 	ft_printf("----- end\n");
// }
// void	divide_sort(t_stack **stack_a, t_stack **stack_b, int max_s_idx)
// {
// 	int		mid;
// 	int		size;

// 	if (check_sorted(*stack_a))
// 		return ;
// 	size = max_s_idx;
// 	//mid =  max_s_idx / 2 + 1;
// 	//mid = find_middle(*stack_a);
// 	mid = find_max_s_idx(*stack_a) -  2;
// 	ft_printf("min = %d | max = %d | mid = %d\n", find_min_s_idx(*stack_a), find_max_s_idx(*stack_a), mid);
// 	ft_printf("stack->sdx = %d\n", (*stack_a)->s_idx);
// 	while (!check_sorted(*stack_a) && size > 3)
// 	{
// 		if ((*stack_a)->s_idx - 1 == (*stack_a)->next->s_idx)
// 			sa(*stack_a);
// 		print_stack(*stack_a);
// 		divide_stack(&*stack_a, &*stack_b, size, mid);
// 		middle_sort(&*stack_a, &*stack_b, mid);
// 		size = find_max_value((*stack_a), &((*stack_a)->index));
// 		// if (find_min_value((*stack_a), &((*stack_a)->s_idx) == mid)
// 		// {
			
// 		// }
// 		ft_printf("size = %d || mid = %d\n", size, mid);
// 		ft_printf("min = %d | max = %d | mid = %d\n", find_min_s_idx(*stack_a), find_max_s_idx(*stack_a), mid);
// 	}
// 	ft_printf("size = %d || mid = %d\n", size, mid);
// }

// void	first_sort(t_stack **stack_a, t_stack **stack_b, int max_s_idx)
// {
// 	t_stack	*target;
// 	int		mid;
// 	int		size;
// 	int		i;

// 	i = 0;
// 	size = max_s_idx;
// 	mid = max_s_idx / 2 + 1;
// 	while (size >= mid && \
// 	find_min_value((*stack_a), &((*stack_a)->s_idx)) < mid)
// 	{
// 		ft_printf("stack : %p \t i:%d \t max= %d || min = %d\n", *stack_a, i, max_s_idx, find_min_value((*stack_a), &((*stack_a)->s_idx)));
// 		if ((*stack_a)->s_idx >= max_s_idx / 2 + 1)
// 		{
// 			target = find_target((*stack_a), 1, size, max_s_idx);
// 			ft_printf("target : %p\t t_index->: %d \t t_s_idx: %d\n", target, \
// 			target->index, target->s_idx);
// 			if (target->index >= size / 2 + 1)
// 			{
// 				while (target != *stack_a)
// 					rra(&*stack_a);			
// 			}
// 			else
// 			{
// 				while (target != *stack_a)
// 					ra(&*stack_a);
// 			}
// 		}
// 		else
// 			pb(&*stack_a, &*stack_b);
// 		print_stack(*stack_a);
// 		print_stack(*stack_b);
// 		middle_sort(&*stack_a, &*stack_b, mid);
// 		size = find_max_value((*stack_a), &((*stack_a)->index));
// 		ft_printf("size :%d\n", size);
// 		ft_printf("mid :%d\n", mid);
// 	}
// }

// void	second_sort(t_stack **stack_a, t_stack **stack_b, int max_s_idx)
// {
	
// }
// find_max_value((*stack_a), &((*stack_a)->index))
// void	first_sort(t_stack **stack_a, t_stack **stack_b, int max_s_idx)
// {
// 	if (!check_sorted(*stack_a))
// 		operations_stack_a(&*stack_a, &*stack_b, max_s_idx);
// 	show_stack(*stack_a, *stack_b);
// 	print_stack(*stack_a);
// 	print_stack(*stack_b);
// 	if (*stack_b)
// 	{
// 		operations_stack_b(&*stack_b, &*stack_a, max_s_idx);
// 	// 	// show_stack(*stack_a, *stack_b);
// 	// 	// print_stack(*stack_a);
// 	// 	// print_stack(*stack_b);
// 	}
// }
