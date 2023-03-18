/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:53:55 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 15:44:29 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//Function moves all elements of a stack a down by one.
void	rev_rotate_a(t_stack *st_a)
{
	reverse_rotate(st_a);
	ft_printf("rra\n");
	stack_display_full(st_a);
}

//Function moves all elements of a stack b down by one.
void	rev_rotate_b(t_stack *st_b)
{
	reverse_rotate(st_b);
	ft_printf("rrb\n");
	stack_display_full(st_b);
}

//Function moves all elements of two stacks a and b down by one.
void	rev_rotate_ab(t_stack *st_a, t_stack *st_b)
{
	reverse_rotate(st_a);
	reverse_rotate(st_b);
	ft_printf("rrr\n");
	stack_display_full(st_a);
	stack_display_full(st_b);
}
