/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:17:58 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/20 13:03:10 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;

	target = find_target_s_idx(*stack_a, -1);
	if (((*stack_a)->s_idx > (*stack_a)->next->s_idx && target->index > 1) ||\
	 (target->index == 1 && (*stack_a)->previous->index == 2))
	{
		if ((*stack_b) && (*stack_b)->next && \
		(*stack_b)->s_idx < (*stack_b)->next->s_idx)
				ss(*stack_a, *stack_b);
		else
			sa(*stack_a);
	}
	else if ((*stack_a)->previous && (*stack_a)->previous->index > 2)
	{
		if (target->index == 1)
			ra(&*stack_a);
		else 
			rra(&*stack_a);
	}
}

void push_b(t_stack **stack_a, t_stack **stack_b, int size)
{

	while((*stack_a)->previous->index > 3)
	{
		if ((*stack_a)->s_idx >= (size - 2))
			ra(&*stack_a);
		else
			pb(&*stack_a, &*stack_b);
	}
	while (!check_sorted_value(*stack_a))
		sort_3(&*stack_a, &*stack_b);
}

void	move_stacks(t_stack *target, t_stack **stack_a, t_stack **stack_b, int type)
{
	t_stack *stack;

	if (type > 0)
		stack = *stack_a;
	else if (type < 0)
		stack = *stack_b;
	else
		stack = NULL;
	// if(find_max_value((*stack_b), &((*stack_b)->index)) == 2)
	
	if (target->weight < 0)
	{
		while (target->weight != 0)
			do_rrotate(&*stack_a, &*stack_b, type);
	}
	else
	{
		while (target->weight != 0)
			do_rotate(&*stack_a, &*stack_b, type);
	}
}

t_stack *get_b(t_stack *target, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*target_b;
	int		tmp_weight;
	int 	min;

	if ((*stack_b)->s_idx < target->s_idx && !(*stack_b)->weight)
		return (*stack_b);
	else
	{
		target_b = *stack_b;
		tmp = *stack_b;
		min = (find_max_value(*stack_b, &(*stack_b)->index) + 1) / 2;
		while(tmp)
		{
			tmp_weight = (*stack_b)->weight;
			 if (tmp_weight < 0)
			 	tmp_weight = -tmp_weight;
			if (min > tmp_weight && tmp->s_idx < target->s_idx)
			{
				min = tmp_weight;
				target_b = tmp;
			}
		}
		return (target_b);
	}
}

t_stack *get_a(t_stack *target, t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*target_b;
	int		tmp_weight;
	int 	min;

	if ((*stack_a)->s_idx > target->s_idx && !(*stack_a)->weight)
		return (*stack_a);
	else
	{
		target_b = *stack_a;
		tmp = *stack_a;
		min = (find_max_value(*stack_a, &(*stack_a)->index) + 1) / 2;
		while(tmp)
		{
			tmp_weight = (*stack_a)->weight;
			 if (tmp_weight < 0)
			 	tmp_weight = -tmp_weight;
			if (min > tmp_weight && tmp->s_idx > target->s_idx)
			{
				min = tmp_weight;
				target_b = tmp;
			}
		}
		return (target_b);
	}
}

t_stack *target_search(t_stack *s_top, t_stack *s_search, int diff_max, int type)
{
	t_stack *target_s;
	int		search_val;
	int		top;

	target_s = s_search;
	while(s_search)
	{
		top = s_search->s_idx;
		search_val =  s_top->s_idx;
		if (type < 0)
		{
			top = s_top->s_idx;
			search_val = s_search->s_idx;
		}	
		if (top > search_val)
		{
			if (diff_max > top - search_val)
			{
				diff_max = top - search_val;
				target_s = s_search;
			}
		}
		s_search = s_search->next;
	}
	return (target_s);
}

int abs(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}
// check when size a > b
void	get_target(t_stack **stack_a, t_stack **stack_b, int diff_max)
{
	t_stack *target_a;
	t_stack *target_b;

	target_a = target_search(*stack_b, *stack_a, diff_max, 1);
	target_b = target_search(*stack_a, *stack_b, diff_max, -1);
	if (abs(target_a->weight) <= abs(target_b->weight))
		target_b = get_b(target_a, &*stack_b);
	if (abs(target_a->weight) > abs(target_b->weight))
		target_a = target_search(target_b, *stack_a, diff_max, 1);
	if (!target_a->weight && !target_b->weight)
	{
		if (target_b->next && target_b->next->s_idx < target_a->s_idx && \
		target_b->next->s_idx > target_a->previous->s_idx)
			sb(*stack_b);
		pa(&*stack_b, &*stack_a);
	}
	else if ((target_a->weight > 0 && target_b->weight> 0) || \
	(target_a->weight < 0 && target_b->weight < 0))
	{
		if (abs(target_a->weight) < abs(target_b->weight))
			move_stacks(target_a, &*stack_a, &*stack_b, 0);
		else
			move_stacks(target_b, &*stack_a, &*stack_b, 0);	
	}
	else 
	{
		move_stacks(target_a, &*stack_a, &*stack_b, 1);
		move_stacks(target_b, &*stack_a, &*stack_b, -1);
	}
}

t_stack *last_ordered(t_stack *stack)
{
	t_stack *tmp_last;

	tmp_last = stack;
	while (tmp_last)
	{
		if (tmp_last->s_idx + 1 != tmp_last->next->s_idx)
			break;
		tmp_last = tmp_last->next;
	}
	return (tmp_last);
}

void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	max_s_idx;
	int	size;

	max_s_idx = find_max_value(*stack_a, &(*stack_a)->s_idx);
	size = max_s_idx;
	if (size > 1 && !check_sorted(*stack_a))
	{
		push_b(&*stack_a, &*stack_b, max_s_idx);
		if (*stack_b)
			pa(&*stack_b, &*stack_a);
		// while (*stack_b)
		while (*stack_b && i++ < 5)
			get_target(&*stack_a, &*stack_b, max_s_idx - 1);
	}
	if (!check_sorted(*stack_a))
		move_stacks(last_ordered(*stack_a)->next, &*stack_a, &*stack_b, 1);
}

	// // while (1)
	// while (i++ < 4 && !check_sorted(*stack_a))
	// {
	// 	move_sort(&*stack_a, &*stack_b);
	// }
	// while (1)
	// while (i++ < 4 && !check_sorted(*stack_a))
	// {
	// 	if (size > 3)
	// 	{
	// 		if((*stack_a)->s_idx >= max_s_idx - 2 && (*stack_a)->s_idx - 1 == (*stack_a)->next->s_idx)
	// 			sa(*stack_a);
	// 		if((*stack_a)->s_idx >= max_s_idx - 2 && last_ordered_element(*stack_a) == *stack_a)
	// 			ra(&*stack_a);
	// 		if (!check_sorted_value(*stack_a))
	// 			move_2b(&*stack_a, &*stack_b, max_s_idx);
	// 		else
	// 			move_sort(&*stack_a, &*stack_b);
	// 	}
	// 	if (size <= 3 && !check_sorted_value(*stack_a))
	// 		sort_3(&*stack_a, &*stack_b);
	// 	if (!*stack_b && check_sorted(*stack_a))
	// 	{
	// 		ft_printf("OK\n");
	// 		return ;
	// 	}
	// 	if((*stack_b && (*stack_b)->s_idx == (*stack_a)->s_idx - 1) || check_sorted(*stack_a))
	// 	{
	// 		pa(&*stack_b, &*stack_a);
	// 	}
	// 	print_stack(*stack_a);
	// 	print_stack(*stack_b);
	// 	size = find_max_value(*stack_a, &(*stack_a)->index);
	// 	ft_printf("********* i = %d, size = %d || max_sdx = %d\n", i, size, max_s_idx);
	// }
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
