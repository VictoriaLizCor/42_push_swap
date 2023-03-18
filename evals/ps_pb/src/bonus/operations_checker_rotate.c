/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:47:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/03 15:44:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker.h"

//Function moves all elements of a stack a up by one. Suppresses message.
void	chk_rotate_a(t_stack *st_a)
{
	rotate(st_a);
}

//Function moves all elements of a stack b up by one. Suppresses message.
void	chk_rotate_b(t_stack *st_b)
{
	rotate(st_b);
}

//Function moves all elements of two stacks a and b up by one. No message.
void	chk_rotate_ab(t_stack *st_a, t_stack *st_b)
{
	rotate(st_a);
	rotate(st_b);
}
