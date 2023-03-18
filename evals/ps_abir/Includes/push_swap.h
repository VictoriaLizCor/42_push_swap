/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:12:31 by mabbas            #+#    #+#             */
/*   Updated: 2022/10/24 03:47:47 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Headers 
 */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"
# include<limits.h>
# include<unistd.h>
# include<stdlib.h> // This is for error Macros
# include<stdbool.h> // This is for boolean flags
# include <stdio.h> // remove later lol

/* ------ Struct for my list of Stack ------ */

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}		t_stack;

/* ------ Node Operations ------  */

t_stack	*ft_new_node(int val);
void	ft_back_add(t_stack **lst, t_stack *new);
void	ft_front_add(t_stack	**lst, t_stack	*new);
int		ft_lst_size(t_stack *lst);
void	ft_lst_del_end(t_stack **stack);
void	ft_del_stack(t_stack **stack);
int		ft_node_find(t_stack *stack, int found);
void	ft_print_stack(t_stack *ptr);

/* ------ Arg Checkers/Error Operations ------  */
bool	ft_stack_build(int argc, char **argv, t_stack **stack);
int		ft_found_duplicate(t_stack *stack);
void	ft_error_msg(bool error);
void	ft_range_num_chk(long res, bool *error);
void	ft_check_valid_input(char *str, bool *error);

	/* ------ Modified libft functions (Arg parsing helpers ------ */
	/* ------ Argument Parsers ------ */
long	ft_atol(char *str, bool *error);
/* -------- Stack Size Checkers ----- */
bool	ft_sorted_stack(t_stack *stack);
bool	ft_stack_small(int size);
bool	ft_stack_medium(int size);
bool	ft_stack_big(int size);

/* ------ Size Checker and Slicers ------ */

void	print_list(t_stack	*head);

/* ------ Sorter Utils ------ */

int		ft_min(t_stack	*stack);
int		ft_max(t_stack *stack);
int		ft_next_max(t_stack *stack, int max);
int		ft_mid(int size);
int		ft_pos(t_stack *stack, int found_pos);
int		ft_find_middle(int size);
int		ft_slice_set(int size);

void	ft_sort_slice_a(t_stack **stack_a, t_stack **stack_b);
void	ft_max_push(t_stack **stack_a, t_stack **stack_b, int max, int min);
void	ft_max_bottom_push(t_stack **stack_a, t_stack **stack_b, int n_max);
void	ft_max_push(t_stack **stack_a, t_stack **stack_b, int max, int mid);
void	ft_max_top_push(t_stack **stack_a, t_stack **stack_b, int n_max);

/* Sorted 3 Numbers or less than 10 */

void	ft_tri_sort(t_stack **stack);
void	ft_sort_stack_b(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_small(t_stack **stack_a, t_stack **stack_b);
/* Sorters for more than 100 numbers */
void	ft_sort_large_elem(t_stack **stack_a, t_stack **stack_b);

/* Sorters for the stack B */
void	ft_max_push(t_stack **stack_a, t_stack **stack_b, int max, int mid);
void	ft_max_top_push(t_stack **stack_a, t_stack **stack_b, int n_max);
void	ft_max_bottom_push(t_stack **stack_a, t_stack **stack_b, int n_max);
void	ft_max_pushes(t_stack **stack_a, t_stack **stack_b, int max, int min);
void	ft_sort_slice_a(t_stack **stack_a, t_stack **stack_b);

/* Stack Commands */
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_revrotate(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

/* Chunking / Slicing Commands */

t_stack	*ft_copy_stack(t_stack *stack_a);
int		ft_next_key(t_stack *stack_key, int slice, int move);
int		ft_key(t_stack **stack_a, t_stack **stack_key, int parts, int move);
void	ft_arg_process(int argc, char **argv, t_stack **stack, bool *error);

#endif