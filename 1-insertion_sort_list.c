#include "sort.h"

/**
 * insertion_sort_list - This function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort.
 * @list: The list for to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *before, *current;

	if (list == NULL || (*list)->next == NULL)
		return;

	temp = *list;
	while (temp)
	{
		while ((temp->prev) && (temp->n < temp->prev->n))
		{
			before = temp->prev;
			current = temp;

			before->next = current->next;
			if (current->next)
				current->next->prev = before;
			current->next = before;
			current->prev = before->prev;
			before->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
			*list = current;
			print_list(*list);
		}
		temp = temp->next;
	}
}
