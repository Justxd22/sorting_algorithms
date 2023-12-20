#include "sort.h"

/**
 * insertion_sort_list - Insertion sort algo.
 *
 * @list: Linked list to sort
 * No Return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	curr = (*list)->next;

	while (curr != NULL)
	{
		temp = curr->prev;
		while (temp != NULL && temp->n > curr->n)
		{
			temp->next = curr->next;
			if (temp->next != NULL)
				temp->next->prev = temp;

			curr->prev = temp->prev;
			if (curr->prev != NULL)
				curr->prev->next = curr;

			temp->prev = curr;
			curr->next = temp;

			if (curr->prev == NULL)
				*list = curr;

			print_list(*list);
			temp = curr->prev;
		}
		curr = curr->next;
	}
}
