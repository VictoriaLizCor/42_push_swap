/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker_reverse_rotate.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:53:55 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/03 15:36:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker.h"

//Function moves all elements of a stack a down by one. Suppresses message.
void	chk_rev_rotate_a(t_stack *st_a)
{
	reverse_rotate(st_a);
}

//Function moves all elements of a stack b down by one. Suppresses message.
void	chk_rev_rotate_b(t_stack *st_b)
{
	reverse_rotate(st_b);
}

//Function moves all elements of two stacks a and b down by one. No message.
void	chk_rev_rotate_ab(t_stack *st_a, t_stack *st_b)
{
	reverse_rotate(st_a);
	reverse_rotate(st_b);
}
