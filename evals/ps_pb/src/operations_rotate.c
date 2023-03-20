/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:47:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/18 23:24:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//Function moves all elements of a stack a up by one.
void	rotate_a(t_stack *st_a)
{
	rotate(st_a);
	ft_printf("ra\n");
}

//Function moves all elements of a stack b up by one.
void	rotate_b(t_stack *st_b)
{
	rotate(st_b);
	ft_printf("rb\n");
}

//Function moves all elements of two stacks a and b up by one.
void	rotate_ab(t_stack *st_a, t_stack *st_b)
{
	rotate(st_a);
	rotate(st_b);
	ft_printf("rr\n");
}
