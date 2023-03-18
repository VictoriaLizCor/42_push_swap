/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:47:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/11 15:46:42 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//Function moves all elements of a stack a up by one.
void	rotate_a(t_stack *st_a)
{
	rotate(st_a);
	ft_printf("ra\n");
	stack_display_full(st_a);
}

//Function moves all elements of a stack b up by one.
void	rotate_b(t_stack *st_b)
{
	rotate(st_b);
	ft_printf("rb\n");
	stack_display_full(st_b);
}

//Function moves all elements of two stacks a and b up by one.
void	rotate_ab(t_stack *st_a, t_stack *st_b)
{
	rotate(st_a);
	rotate(st_b);
	ft_printf("rr\n");
	stack_display_full(st_a);
	stack_display_full(st_b);
}
