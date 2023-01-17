/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:22:17 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/17 13:43:18 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"

/*
value	=	input data
index	=	stack array;
weight	=	idx - value;
head	=	first stack element
tail	=	last stack element
s_idx	=	sorted values index
*/
typedef struct s_stack
{
	int				value;
	int				index;
	int				weight;
	int				head;
	int				tail;
	int				s_idx;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

void	check_after_string_data(char *str, int ret, int extra);
void	print_stack(t_stack *list);
void	show_stack(t_stack *stack_a, t_stack *stack_b);
void	check_integers(char **argv);
void	check_repeated(t_stack *stack);
void	ft_error(void);

/* Instructions*/
/* swap.c */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
/* rotate.c */
void	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
/* reverse_rotate.c */
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/* pop_push.c*/
void	push_pop(t_stack **stack_src, t_stack **stack_dst);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
/* update.c */
t_stack	*stack_last(t_stack *stack);
void	update_weight(t_stack *stack);
#endif