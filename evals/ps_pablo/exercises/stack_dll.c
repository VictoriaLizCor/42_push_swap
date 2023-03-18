#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*start;
	t_node	*top;
}			t_stack;

//Function pushes (new) data to the top of the stack.
void	push(int num, t_stack *stack)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->num = num;
	//If stack is empty, make as new node.
	if (stack->top == 0)
	{
		//No previous or next node.
		new->prev = 0;
		new->next = 0;
		//Stack beginning is here.
		stack->start = new;
	}
	else
	{
		//Next node after previous top is new.
		stack->top->next = new;
		//Last node so next is null.
		new->next = 0;
		//Previous becomes old top.
		new->prev = stack->top;
	}
	//Top is now the new node.
	stack->top = new;
}

//Function determines the size of the stack.
int	stack_size(t_stack *stack)
{
	int		i;
	t_node	*ptr;

	i = 0;
	if (stack->top == 0)
		return (0);
	ptr = stack->start;
	while (ptr != 0)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

//Function displays the current state of a stack.
void	display_stack(t_stack *stack)
{
	t_node	*ptr;

	printf("Stack size: %d\n", stack_size(stack));
	ptr = stack->top;
	while (ptr != 0)
	{
		printf("%d\n", ptr->num);
		ptr = ptr->prev;
	}
}

//Function frees a stack.
void	freestack(t_stack *stack)
{
	t_node	*ptr;
	t_node	*hold;

	ptr = stack->start;
	while(ptr != 0)
	{
		hold = ptr->next;
		free(ptr);
		ptr = hold;	
	}
	free(stack);
}

int	main(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	push(5, stack);
	push(56, stack);
	push(516, stack);
	push(97, stack);
	display_stack(stack);
	freestack(stack);
}
