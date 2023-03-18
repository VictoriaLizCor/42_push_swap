/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:51:11 by hhasni            #+#    #+#             */
/*   Updated: 2014/05/12 17:52:21 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP
# define PUSHSWAP

# include <stdlib.h>
# include <unistd.h>

typedef struct  	s_list
{
	int				nb;
	int				i;
	struct s_list 	*next;
}					t_list;

int					ft_strlen(char *s);
char				*ft_strdup(char *str);
void				ft_fill(t_list **l, int nb);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putnbr(int n);
void				ft_putchar(char c);
t_list				*ft_fill_first(t_list **l, int nb);
void				ft_pushswap(t_list *la, t_list *lb, int v);
int					ft_is_order(t_list *l);
int					ft_is_min(int bkp, t_list *l);
t_list				*ft_pb(t_list *la, t_list **lb);
t_list				*ft_pa(t_list *lb, t_list **la, int v);
void				*ft_ra(t_list *la);
#endif
