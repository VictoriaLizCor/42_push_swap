/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:53:55 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/21 03:41:53 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//Function moves all elements of a stack a down by one.
void	rev_rotate_a(t_stack *st_a)
{
	reverse_rotate(st_a);
	ft_printf("rra\n");
}

//Function moves all elements of a stack b down by one.
void	rev_rotate_b(t_stack *st_b)
{
	reverse_rotate(st_b);
	ft_printf("rrb\n");
}

//Function moves all elements of two stacks a and b down by one.
void	rev_rotate_ab(t_stack *st_a, t_stack *st_b)
{
	reverse_rotate(st_a);
	reverse_rotate(st_b);
	ft_printf("rrr\n");
}
