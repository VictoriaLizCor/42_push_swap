/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:11:13 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/05 10:42:54 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//seq -1000 2000 | sort -R | tail -n 1000 | tr '\n' ' '
#include "./lib/libft/libft.h"
/*
3 numbers <= 3 moves,
5 numbers <= 12 moves, 
100 numbers <= 700 moves
500 numbers <= 5500
*/

/* Rules
non_repetive number to stack -> error if found
+/- numbers allowed
INT_MIN < numbers < INT_MAX
Stack_A -> initialized with random numbers
Stack -> empty
sort in ascending order 
*/

/* Instructions 
sa  / sb  / ss
ra  / rb  / rr
rra / rrb / rrr
pa 	/ pb
*/

int	main(void)
{
	ft_printf("HOLA\n");
	return (0);
}
