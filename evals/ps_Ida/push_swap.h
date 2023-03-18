/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:27:06 by iczarnie          #+#    #+#             */
/*   Updated: 2022/04/24 20:27:06 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				a_score;
	int				b_score;
	int				a_rev_score;
	int				b_rev_score;
	int				rank;
	struct s_node	*next;
}	t_node;

int					ft_isdigit(int c);
long long int		ft_atoi(char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				do_rab(t_node **stack, int write, char x);
void				do_rr(t_node **stack_a, t_node **stack_b);
void				add_back(t_node **stack, t_node *new);
void				add_front(t_node **lst, t_node *new);
void				do_rrab(t_node **stack, int write, char x);
void				do_rrr(t_node **stack_a, t_node **stack_b);
void				do_sab(t_node **stack, int write, char x);
void				do_ss(t_node **stack_a, t_node **stack_b);
void				do_pb(t_node **stack_a, t_node **stack_b, int write);
void				do_pa(t_node **stack_a, t_node **stack_b, int write);
void				sort_three(t_node **stack);
t_node				*to_b(t_node **stack);
t_node				*last(t_node *stack);
void				score_b(t_node *stack_b);
void				score_a(t_node *stack_a, t_node *stack_b);
int					stack_length(t_node *stack);
int					final_score(t_node *stack, int *operation_type_key);
t_node				*chose_move(t_node *stack, int *operation_type_key);
void				execute_operations(t_node **stack_a, t_node **stack_b,
						t_node *node, int *operation_type_key);
t_node				*new_node(int value);
void				add_back(t_node **stack, t_node *new);
void				create_stack(t_node **stack, t_node *new);
int					stack_length(t_node *stack);
int					*populate_array(t_node *stack, int length);
int					*create_and_sort_array(t_node **stack);
void				ranks(t_node *stack, int *array);
void				min_max_med(t_node **stack, int *min, int *max, int *med);
void				move_to_a(t_node **stack_a, t_node **stack_b);
void				final_sort(t_node **stack);
t_node				*to_b(t_node **stack);
int					digits_limits_check(char *argv);
int					error_check(int argc, char **argv);
int					duplicate_check(t_node **stack_a);
void				error(void);
void				score(t_node **stack_a, t_node **stack_b);
size_t				ft_strlen(const char *str);
void				free_stack(t_node **stack);
int					duplicate_second(int *first, int *second,
						int length, t_node **stack_a);

#endif