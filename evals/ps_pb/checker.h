/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:20:14 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/03 15:37:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "pushswap.h"

// OPERATIONS
//Function pushes the top element of stack b to stack a. Suppresses message.
void	chk_push_a(t_stack *st_a, t_stack *st_b);
//Function pushes the top element of stack a to stack b. Suppresses message.
void	chk_push_b(t_stack *st_a, t_stack *st_b);
//Function swaps the first two elements on a stack a. Suppresses message.
void	chk_swap_a(t_stack *st_a);
//Function swaps the first two elements on a stack b. Suppresses message.
void	chk_swap_b(t_stack *st_b);
//Function swaps the first two elements of each of two stacks a and b. No msg.
void	chk_swap_ab(t_stack *st_a, t_stack *st_b);
//Function moves all elements of a stack a up by one. Suppresses message.
void	chk_rotate_a(t_stack *st_a);
//Function moves all elements of a stack b up by one. Suppresses message.
void	chk_rotate_b(t_stack *st_b);
//Function moves all elements of two stacks a and b up by one. No message.
void	chk_rotate_ab(t_stack *st_a, t_stack *st_b);
//Function moves all elements of a stack a down by one. Suppresses message.
void	chk_rev_rotate_a(t_stack *st_a);
//Function moves all elements of a stack b down by one. Suppresses message.
void	chk_rev_rotate_b(t_stack *st_b);
//Function moves all elements of two stacks a and b down by one. No message.
void	chk_rev_rotate_ab(t_stack *st_a, t_stack *st_b);

#endif
