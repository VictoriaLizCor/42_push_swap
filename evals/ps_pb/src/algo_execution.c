/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:05:16 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/31 13:39:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <limits.h>
#include <stdlib.h>

//Function rotates stack a in both directions according to the cost value.
static void	opt_rotate_a(t_stack *stack_a, int *cost_a_cp)
{
	while (*cost_a_cp != 0)
	{
		if (*cost_a_cp > 0)
		{
			rotate_a(stack_a);
			(*cost_a_cp)--;
		}
		else if (*cost_a_cp < 0)
		{
			rev_rotate_a(stack_a);
			(*cost_a_cp)++;
		}
	}
}

//Function rotates stack b in both directions according to the cost value.
static void	opt_rotate_b(t_stack *stack_b, int *cost_b_cp)
{
	while (*cost_b_cp != 0)
	{
		if (*cost_b_cp > 0)
		{
			rotate_b(stack_b);
			(*cost_b_cp)--;
		}
		else if (*cost_b_cp < 0)
		{
			rev_rotate_b(stack_b);
			(*cost_b_cp)++;
		}
	}
}

//Function rotates stacks a and b according to the cost values.
static void	opt_rotate_ab(t_stack *stack_a, t_stack *stack_b, \
								int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_ab(stack_a, stack_b);
	}
}

//Function reverse rotates stacks a and b according to the cost values.
static void	opt_rev_rotate_ab(t_stack *stack_a, t_stack *stack_b,
								int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rev_rotate_ab(stack_a, stack_b);
	}
}

//Function performs stack operations until costs are exhausted. Cheapest node.
void	perform_operations(t_stack *stack_a, t_stack *stack_b)
{
	int		*cost_a_cp;
	int		*cost_b_cp;
	t_node	*node;

	node = stack_cost_min(stack_b);
	cost_b_cp = (int *)malloc(sizeof(int));
	cost_a_cp = (int *)malloc(sizeof(int));
	*cost_a_cp = node->cost_a;
	*cost_b_cp = node->cost_b;
	if (*cost_a_cp < 0 && *cost_b_cp < 0)
		opt_rev_rotate_ab(stack_a, stack_b, cost_a_cp, cost_b_cp);
	else if (*cost_a_cp > 0 && *cost_b_cp > 0)
		opt_rotate_ab(stack_a, stack_b, cost_a_cp, cost_b_cp);
	opt_rotate_a(stack_a, cost_a_cp);
	opt_rotate_b(stack_b, cost_b_cp);
	push_a(stack_a, stack_b);
	free(cost_a_cp);
	free(cost_b_cp);
}
