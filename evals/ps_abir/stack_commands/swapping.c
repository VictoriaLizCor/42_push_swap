/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:34:04 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/24 22:15:50 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

/**
 * @brief This swaps the first 2 elements at the top of stack a
 * **	  Nothing is done when only one or no elements.
 * 
 * @param stack 
 */
void	ft_sa(t_stack	**stack_a)
{
	int		temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->val;
	(*stack_a)->val = (*stack_a)->next->val;
	(*stack_a)->next->val = temp;
	write (1, "sa\n", 3);
}

/**
 * @brief Swapping the first 2 elements at the top of stack b
 *        Nothing is done when only one or no elements
 * 
 * @param stack_b 
 */
void	ft_sb(t_stack	**stack_b)
{
	int	temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->val;
	(*stack_b)->val = (*stack_b)->next->val;
	(*stack_b)->next->val = temp;
	write (1, "sb\n", 3);
}

/**
 * @brief ss ( sa and sb at the same time)
 * 
 */

void	ft_ss(t_stack	**stack_a, t_stack	**stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	ft_sa(stack_a);
	ft_sb(stack_b);
	write (1, "ss\n", 3);
}
