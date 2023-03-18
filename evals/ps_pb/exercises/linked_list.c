#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}					t_node;

//Function creates a list with n nodes.
void	*list_create(int n, int *arr)
{
	int		i;
	t_node	*fn_node, *temp;
	t_node	*first_node;

	//Allocate memory for the first node.
	first_node = (t_node *)malloc(sizeof(t_node));
	if (!first_node)
	{
		printf("Malloc failed.\n");
		return (0);
	}
	i = 0;
	while (i < n)
	{
		if (i == 0)
		{
			first_node->num = arr[i];
			first_node->next = 0;
			temp = first_node;
		}
		else
		{
			//Allocate memory for each new node.
			fn_node = (t_node *)malloc(sizeof(t_node));
			if (!fn_node)
			{
				printf("Malloc failed.\n");
				return (0);
			}
			fn_node->num = arr[i];
			fn_node->next = 0;
			//Previous node's next is assigned to current node.
			temp->next = fn_node;
			//Temp becomes current node. (Previous to-be)
			temp = temp->next;
		}
		i++;
	}
	return (first_node);
}

//Function displays a linked list.
void	list_display(void *first_node)
{
	t_node	*node;

	node = first_node;
	while (node != (void *) 0)
	{
		printf("Value: %d\n", node->num);
		node = node->next;
	}
}

//Function to free list memory.
void	list_free(t_node *list)
{
	t_node	*freedata = list;
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
	int		list[4] = {4, 56, 342, 121};
	t_node	*listone;

	listone = list_create(4, list);
	list_display(listone);
	list_free(listone);
	return (0);
}
