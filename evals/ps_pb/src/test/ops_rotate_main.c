// Tests for functions in operations_rotate.c
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

/* Test for rotate_a rotate_b and rotate_ab
// run: cc ops_rotate_main.c ../operations_rotate.c ../stack_operations.c ../stack_special.c ../memory.c test.c ../../libft/libft.a
int	main(void)
{
	t_stack	*stacka;
	t_stack *stackb;

	stacka = (t_stack *)malloc(sizeof(t_stack));
	stackb = (t_stack *)malloc(sizeof(t_stack));
	push(50, stacka);
	push(150, stacka);
	push(250, stacka);
	push(5, stackb);
	push(15, stackb);
	push(25, stackb);
	printf("Stack A:\n");
	stack_display(stacka);
	printf("Stack B:\n");
	stack_display(stackb);
	rotate_a(stacka);
	stack_display(stacka);
	rotate_b(stackb);
	stack_display(stackb);
	rotate_ab(stacka, stackb);
	printf("Stack A:\n");
	stack_display(stacka);
	printf("Stack B:\n");
	stack_display(stackb);
	free_stack(stacka);
	free_stack(stackb);
	return (0);
}
//*/
