void	operations_stack_b(t_stack **stack_b, t_stack **stack_a, int max_s_idx)
{
	ft_printf("op_b: \t");
	if ((*stack_a)->s_idx - 1 == (*stack_b)->s_idx && \
	check_sorted(*stack_a))
		pa(&*stack_b, &*stack_a);
	if (*stack_b && (*stack_b)->next)
	{
		if ((*stack_b)->s_idx + 1 == (*stack_b)->next->s_idx)
			sb((*stack_b));
		else if ((*stack_b)->s_idx == \
		find_min_value((*stack_b), &((*stack_b)->s_idx)))
			rb(&*stack_b);
		else if ((*stack_b)->previous->s_idx == \
		find_max_value((*stack_b), &((*stack_b)->s_idx)))
			rb((&*stack_b));
		else if ((*stack_b)->s_idx + 1 == (*stack_b)->previous->s_idx)
			rrb((&*stack_b));
		else if ((*stack_b)->s_idx < \
		find_max_value((*stack_b), &((*stack_b)->index)))
			rb((&*stack_b));
		else
		{
			if (max_s_idx > 3 && (*stack_b)->s_idx > (max_s_idx / 2) + 1 && \
			!check_sorted(*stack_a))
				pa(&*stack_b, &*stack_a);
		}
	}
}

int	consecutive_value(t_stack **stack)
{
	if ((*stack)->s_idx + 1 == (*stack)->previous->s_idx || \
		(*stack)->s_idx + 1 == (*stack)->next->s_idx)
		return (1);
	else if ((*stack)->s_idx - 1 == (*stack)->previous->s_idx || \
		(*stack)->s_idx - 1 == (*stack)->next->s_idx)
		return (1);
	else
		return (0);
}

void	operations_stack_a(t_stack **stack_a, t_stack **stack_b, int max_s_idx)
{
	ft_printf("op_a: \t");
	if (consecutive_value(&*stack_a))
	{
		if ((*stack_a)->s_idx - 1 == (*stack_a)->next->s_idx)
		{
			if ((*stack_a)->s_idx + 1 == (*stack_a)->previous->s_idx && \
			find_max_value((*stack_a), &((*stack_a)->index)) > 3)
				rra(&*stack_a);
			else
				sa((*stack_a));
		}
		else if ((*stack_a)->previous->s_idx == \
		find_min_value((*stack_a), &((*stack_a)->s_idx)))
			rra(&*stack_a);
		else if ((*stack_a)->s_idx + 1 == (*stack_a)->previous->s_idx)
			rra((&*stack_a));
		else if ((*stack_a)->s_idx - 1 == (*stack_a)->previous->s_idx)
			ra((&*stack_a));
		else if ((*stack_a)->s_idx >= (max_s_idx / 2) + 1)
			ra((&*stack_a));
		else if (max_s_idx > 3 && (*stack_a)->s_idx < \
		(max_s_idx / 2) + 1 && !check_sorted(*stack_a))
			pb(&*stack_a, &*stack_b);
	}
	else
	{
		if (max_s_idx > 3 && (*stack_a)->s_idx < \
		(max_s_idx / 2) + 1)
			pb(&*stack_a, &*stack_b);
		else
			rra(&*stack_a);
	}
}
