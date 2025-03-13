/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:17:58 by lilizarr          #+#    #+#             */
/*   Updated: 2023/03/21 15:46:41 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_stacks(t_stack *target, t_stack **stack_a, \
t_stack **stack_b, int type)
{
	t_stack	*stack;

	if (type > 0)
		stack = *stack_a;
	else if (type < 0)
		stack = *stack_b;
	else
		stack = NULL;
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
	show_stack(*stack_a, *stack_b);
}

static void	target_search_ext(t_stack *tmp_a, t_stack *tmp_b, \
t_targets *targets, int *min_moves)
{
	int	prev;

	prev = tmp_a->previous->s_idx;
	if (prev > tmp_a->s_idx)
		prev = 0;
	while (tmp_b)
	{
		if (tmp_a->s_idx > tmp_b->s_idx && tmp_b->s_idx > prev)
		{
			if (abs(tmp_a->weight) + abs(tmp_b->weight) <= *min_moves)
			{
				*min_moves = abs(tmp_a->weight) + abs(tmp_b->weight);
				targets->a = tmp_a;
				targets->b = tmp_b;
			}
		}
		tmp_b = tmp_b->next;
	}
}

static void	target_search(t_stack *stack_a, t_stack *stack_b, \
t_targets *t, int diff_max)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		min_moves;
	int		prev;

	min_moves = diff_max;
	tmp_a = stack_a;
	while (tmp_a)
	{
		tmp_b = stack_b;
		target_search_ext(tmp_a, tmp_b, &*t, &min_moves);
		tmp_a = tmp_a->next;
	}
	prev = stack_a->previous->s_idx;
	if (prev > stack_a->s_idx)
		prev = 0;
	if (!(t->a)->weight && !(t->b)->weight)
	{
		if (((t->b)->next && (t->b)->next->s_idx < (t->a)->s_idx) && \
		prev < (t->b)->s_idx && (t->b)->s_idx < (t->b)->next->s_idx)
			do_swap(stack_a, stack_b, -1);
	}
}

static void	sort_target(t_stack **stack_a, t_stack **stack_b, int diff_max)
{
	static t_targets	targets;

	///////
	ft_printf("\nsize_a = %d| size_b = %d\n", (*stack_a)->previous->index, (*stack_b)->previous->index);

	target_search(*stack_a, *stack_b, &targets, diff_max);


	////////////
	ft_printf("ta -> %p , ta_idx -> %d , ta_sdx = %d, ta_weigth = %d\n", targets.a, (targets.a)->index , (targets.a)->s_idx, (targets.a)->weight);
	ft_printf("tb -> %p , tb_idx -> %d , tb_sdx = %d, tb_weigth = %d\n", targets.b, (targets.b)->index , (targets.b)->s_idx, (targets.b)->weight);
	ft_printf("w_a = [ %d | %d ] =w_b\n\n",abs((targets.a)->weight), abs((targets.b)->weight));
	/////

	if (!(targets.a)->weight && !(targets.b)->weight)
		pa(&*stack_b, &*stack_a);
	else if (((targets.a)->weight > 0 && (targets.b)->weight > 0) || \
	((targets.a)->weight < 0 && (targets.b)->weight < 0))
	{
		if (abs((targets.a)->weight) < abs((targets.b)->weight))
			move_stacks(targets.a, &*stack_a, &*stack_b, 0);
		else
			move_stacks(targets.b, &*stack_a, &*stack_b, 0);
	}
	else
	{
		if ((targets.a)->weight != 0)
			move_stacks(targets.a, &*stack_a, &*stack_b, 1);
		if ((targets.b)->weight != 0)
		{
			if ((*stack_b)->previous && (*stack_b)->previous->index > 2)
				move_stacks(targets.b, &*stack_a, &*stack_b, -1);
			else if ((*stack_b)->previous && (*stack_b)->previous->index == 2)
				do_swap(*stack_a, *stack_b, -1);
		}
	}
	show_stack(*stack_a, *stack_b);
}

void	sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	show_stack(*stack_a, *stack_b);
	size = find_max_value(*stack_a, &(*stack_a)->s_idx);
	if (size > 1 && !check_sorted(*stack_a))
	{
		push_b(&*stack_a, &*stack_b, size);
		show_stack(*stack_a, *stack_b);
		while (*stack_b)
			sort_target(&*stack_a, &*stack_b, size - 1);
	}
	if (!check_sorted_value(*stack_a))
		move_stacks(last_ordered(*stack_a)->next, &*stack_a, &*stack_b, 1);
	// show_stack(*stack_a, *stack_b);
}
