#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int	num;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

//Function creates a doubly-linked list with n nodes and values from an array.
void	*double_list_create(int	n, int *arr)
{
	int		i;
	t_node	*start_node;
	t_node	*end_node;
	t_node	*regular_node;
	void	**out[2];

	start_node = (t_node *)malloc(sizeof(t_node));
	if (!start_node)
	{
		printf("Malloc error.\n");
		return (0);
	}
	i = 0;
	while (i < n)
	{
		if (i == 0)
		{
			start_node->num = arr[i];
			start_node->prev = 0;
			start_node->next = 0;
			end_node = start_node;
		}
		regular_node = (t_node *)malloc(sizeof(t_node));
		regular_node->num = arr[i];
		regular_node->prev = end_node;
		regular_node->next = 0;
		//Previous last node next assigned to current node.
		end_node->next = regular_node;
		end_node = regular_node;
		i++;
	}
	return (start_node);
}


//Function displays doubly-linked list.
void	list_double_display(t_node *first_node)
{
	t_node	*node;

	node = first_node;
	while (node != (void *) 0)
	{
		printf("Value: %d\n", node->num);
		node = node->next;
	}
}

//Function frees doubly-linked list.
void	list_double_free(t_node *start)
{
	t_node	*freedata = start;
	t_node	*hold = (void *) 0;

	while (freedata != (void *) 0)
	{
		hold = freedata->next;
		free(freedata);
		freedata = hold;
	}
}

//Program to create and display a linked list.
int	main(void)
{
	int		list[6] = {4, 56, 342, 121, 8, 34};
	t_node	*listone;

	listone = (t_node *)double_list_create(6, list);
	list_double_display(listone);
	list_double_free(listone);
	return (0);
}
