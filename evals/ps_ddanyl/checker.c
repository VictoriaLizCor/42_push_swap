/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:26:54 by dsas              #+#    #+#             */
/*   Updated: 2023/01/27 14:00:29 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	if_statements(t_list **a, t_list **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		ft_pa_no_output(a, b);
	else if (!ft_strcmp(cmd, "pb\n"))
		ft_pb_no_output(a, b);
	else if (!ft_strcmp(cmd, "sa\n"))
		ft_swap(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		ft_swap(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		ft_ss_no_output(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		ft_rotate(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		ft_rotate(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		ft_rr_no_output(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		ft_revrotate(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		ft_revrotate(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		ft_rrr_no_output(a, b);
	else
		return (0);
	return (1);
}

void	display_result(t_list *a, t_list *b)
{
	if (ft_issorted(a) && b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_list	*b;
	t_list	*a;
	char	*cmd;

	if (argc < 2)
		return (0);
	b = NULL;
	if (!ft_get_input(argc, argv, &a))
		throw_error(&a);
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (!if_statements(&a, &b, cmd))
		{
			ft_lstclear(&b, free);
			throw_error(&a);
		}
		free(cmd);
	}
	display_result(a, b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}
