#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		next_node = curr->next;
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			prev = curr->prev;

			prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev;

			curr->prev = prev->prev;
			curr->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = curr;
			else
				*list = curr;

			prev->prev = curr;

			print_list(*list);
		}
		curr = next_node;
	}
}
