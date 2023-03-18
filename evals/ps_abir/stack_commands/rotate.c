/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:16:14 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/24 22:27:59 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

/**
 * @brief Shift up all elements of stack a by 1
 *        First element becomes the last one.
 *        operation. We can try otherways too by
 *         creating new nodes.
 * 
 * @param stack_a 
 */

void	ft_ra(t_stack **stack_a)
{
	t_stack	*temp;

	temp = NULL;
	if (!*stack_a)
		return ;
	temp = ft_new_node((*stack_a)->val);
	ft_back_add(stack_a, temp);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(temp);
	temp = NULL;
	write(1, "ra\n", 3);
}

// void	ft_rb(t_stack **stack_b)
// {
// 	t_stack	*tmp;
// 	t_stack	*lst;

// 	// if ((*stack_b)->next == NULL)
// 		// return ((void)write(1, "ra\n", 3));
// 	tmp = *stack_b;
// 	lst = *stack_b;
// 	// stack_b = &(*stack_b)->next;
// 	*stack_b = (*stack_b)->next;
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	lst->next = tmp;
// 	tmp->next = NULL;
// 	write (1, "rb\n", 3);
// }

// void	ft_rb(t_stack **stack_b)
// {
// 	t_stack	*tmp;
// 	t_stack	*lst;

// 	if ((*stack_b)->next == NULL)
// 		return ((void)write(1, "rb\n", 3));
// 	tmp = *stack_b;
// 	lst = *stack_b;
// 	*stack_b = (*stack_b)->next;
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	lst->next = tmp;
// 	tmp->next = NULL;
// 	write(1, "rb\n", 3);
// }

void	ft_rb(t_stack **stack_b)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	if ((*stack_b)->next == NULL)
		return ((void) write(1, "rb\n", 3));
	temp = ft_new_node((*stack_b)->val);
	ft_back_add(stack_b, temp);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(temp);
	temp = NULL;
	write(1, "rb\n", 3);
}

/**
 * @brief  Combination of ra and rb instructions
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b)
		return ;
	ft_ra(stack_a);
	ft_rb(stack_b);
	write (1, "rr\n", 3);
}
