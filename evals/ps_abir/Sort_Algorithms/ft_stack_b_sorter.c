/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_b_sorter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:07:04 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/24 14:53:49 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

/**
 * @brief With this I find max elem in the stack and 
 *        move it to the top by rotate or rev rotate
 *        depending on the pos, considering the 
 *        stack middle.
 * 
 * @param stack_a 
 * @param stack_b 
 * @param max 
 * @param mid 
 */
void	ft_max_push(t_stack **stack_a, t_stack **stack_b, int max, int mid)
{
	int	max_pos;

	max_pos = ft_node_find(*stack_b, max);
	while (max_pos != 1)
	{
		if (max_pos <= mid)
			ft_rb(stack_b);
		else if (max_pos > mid)
			ft_rrb(stack_b);
		max_pos = ft_node_find(*stack_b, max);
	}
	ft_pa(stack_a, stack_b);
}

/**
 * @brief I rotate stakc B until next
 *        max pos is on the top
 *        then push elem to stack A.
 * 
 * @param stack_a 
 * @param stack_b 
 * @param n_max 
 */
void	ft_max_top_push(t_stack **stack_a, t_stack **stack_b, int n_max)
{
	int	pos_n_max;

	pos_n_max = ft_node_find(*stack_b, n_max);
	while (pos_n_max != 1)
	{
		ft_rb(stack_b);
		pos_n_max = ft_node_find(*stack_b, n_max);
	}
	ft_pa(stack_a, stack_b);
}

void	ft_max_bottom_push(t_stack **stack_a, t_stack **stack_b, int n_max)
{
	int	pos_n_max;

	pos_n_max = ft_node_find(*stack_b, n_max);
	while (pos_n_max != 1)
	{
		ft_rrb(stack_b);
		pos_n_max = ft_node_find(*stack_b, n_max);
	}
	ft_pa(stack_a, stack_b);
}

/**
 * @brief 1.Found pos of 2 val in stack_b: max and n_max
 *        3 Conditions I followed here:
 *        a) if n_max is over max and both pos are over middle
 *        ->> Rotated until n_max is on top then pushed to
 *            stack_b.
 *        -->rotated until max is on top of stack --> pushed max
 *        --> switched n_max and max on stack A
 *       b) IF n_max is under max in stack and pos are  both under mid
 *          --> rev rotated until n_max is on top --> pushed
 *          -->rev rotated until max is on top of stack-_> push max
 *          --> switched nmax and max on Stack A.
 *       c) -> Rotate/Rev rotate and push only the Max elem
 *       example : 10 14 15 18 23 25 ---> push 25 
 *           
 * 
 * @param stack_a 
 * @param stack_b 
 * @param max 
 * @param min 
 */
void	ft_max_pushes(t_stack **stack_a, t_stack **stack_b, int max, int n_max)
{
	int	max_pos;
	int	pos_n_max;
	int	size;
	int	mid;

	size = ft_lst_size(*stack_b);
	mid = ft_mid(size);
	max_pos = ft_node_find(*stack_b, max);
	pos_n_max = ft_node_find(*stack_b, n_max);
	if ((max_pos <= mid) && (pos_n_max < mid) && (pos_n_max < max_pos))
	{
		ft_max_top_push(stack_a, stack_b, n_max);
		mid--;
		ft_max_push(stack_a, stack_b, max, mid);
		ft_sa(stack_a);
	}
	else if ((max_pos > mid) && (pos_n_max > mid) && (pos_n_max > max_pos))
	{
		ft_max_bottom_push(stack_a, stack_b, n_max);
		mid--;
		ft_max_push(stack_a, stack_b, max, mid);
		ft_sa(stack_a);
	}
	else
		ft_max_push(stack_a, stack_b, max, mid);
}

/**
 * @brief Here sorting the pushed chunkes
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	ft_sort_slice_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	n_max;

	if (!stack_b)
		return ;
	max = 0;
	n_max = 0;
	while (*stack_b != NULL)
	{
		max = ft_max(*stack_b);
		if ((*stack_b)->next != NULL)
			n_max = ft_next_max(*stack_b, max);
		ft_max_pushes(stack_a, stack_b, max, n_max);
	}
}
