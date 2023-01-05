/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:45:48 by lilizarr          #+#    #+#             */
/*   Updated: 2023/01/04 11:46:54 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* Approach 2: This approach is simpler and uses log n space.
mergeSort():

    If the size of the linked list is 1 then return the head
    Find mid using The Tortoise and The Hare Approach
    Store the next of mid in head2 i.e. the right sub-linked list.
    Now Make the next midpoint null.
    Recursively call mergeSort() on both left and right sub-linked list and store the new head of the left and right linked list.
    Call merge() given the arguments new heads of left and right sub-linked lists and store the final head returned after merging.
    Return the final head of the merged linkedlist.

merge(head1, head2):

    Take a pointer say merged to store the merged list in it and store a dummy node in it.
    Take a pointer temp and assign merge to it.
    If the data of head1 is less than the data of head2, then, store head1 in next of temp & move head1 to the next of head1.
    Else store head2 in next of temp & move head2 to the next of head2.
    Move temp to the next of temp.
    Repeat steps 3, 4 & 5 until head1 is not equal to null and head2 is not equal to null.
    Now add any remaining nodes of the first or the second linked list to the merged linked list.
    Return the next of merged(that will ignore the dummy and return the head of the final merged linked list
 */

// Node structure
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// function to insert in list
void insert(int x, Node** head)
{
	if (*head == NULL) {
		*head = (Node*)malloc(sizeof(Node));
		(*head)->data = x;
		(*head)->next = NULL;
		return;
	}
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = (*head)->data;
	temp->next = (*head)->next;
	(*head)->data = x;
	(*head)->next = temp;
}

// function to print the list
void print(Node* head)
{
	Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

Node* merge(Node* firstNode, Node* secondNode)
{
	Node* merged = (Node*)malloc(sizeof(Node));
	Node* temp = (Node*)malloc(sizeof(Node));

	// merged is equal to temp so in the end we have the top
	// Node.
	merged = temp;

	// while either firstNode or secondNode becomes NULL
	while (firstNode != NULL && secondNode != NULL) {

		if (firstNode->data <= secondNode->data) {
			temp->next = firstNode;
			firstNode = firstNode->next;
		}

		else {
			temp->next = secondNode;
			secondNode = secondNode->next;
		}
		temp = temp->next;
	}

	// any remaining Node in firstNode or secondNode gets
	// inserted in the temp List
	while (firstNode != NULL) {
		temp->next = firstNode;
		firstNode = firstNode->next;
		temp = temp->next;
	}

	while (secondNode != NULL) {
		temp->next = secondNode;
		secondNode = secondNode->next;
		temp = temp->next;
	}
	// return the head of the sorted list
	return merged->next;
}

// function to calculate the middle Element
Node* middle(Node* head)
{
	Node* slow = head;
	Node* fast = head->next;

	while (!slow->next && (!fast && !fast->next)) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

// function to sort the given list
Node* sort(Node* head)
{

	if (head->next == NULL) {
		return head;
	}

	Node* mid = (Node*)malloc(sizeof(Node));
	Node* head2 = (Node*)malloc(sizeof(Node));
	mid = middle(head);
	head2 = mid->next;
	mid->next = NULL;
	// recursive call to sort() hence diving our problem,
	// and then merging the solution
	Node* finalhead = merge(sort(head), sort(head2));
	return finalhead;
}

int main(void)
{
	Node* head = NULL;
	int n[] = { 7, 10, 5, 20, 3, 2 };
	for (int i = 0; i < 6; i++) {
		insert(n[i], &head); // inserting in the list
	}
	printf("Sorted Linked List is: \n");
	print(sort(head)); // printing the sorted list returned
					// by sort()
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
