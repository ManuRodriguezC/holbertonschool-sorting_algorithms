#include "sort.h"

/**
 * swap_nodes - function tha swaps two nodes
 * @node_one: node one
 * @node_two: node two
 * Return: void
 */
void swap_nodes(listint_t *node_one, listint_t *node_two)
{
	if (node_one->prev)
		node_one->prev->next = node_two;
	if (node_two->next)
		node_two->next->prev = node_one;
	node_one->next = node_two->next;
	node_two->prev = node_one->prev;
	node_one->prev = node_two;
	node_two->next = node_one;
}

/**
 * reverse - goes trough a list backwards
 * @head: pointer to the current node
 * @tail: pointer to the tail of the list
 * @list: pointer to the list
 * Return: pointer to the first node
 */
listint_t *reverse(listint_t *head, listint_t *tail, listint_t **list)
{
	while (tail && tail->prev)
	{
		if (tail->n < tail->prev->n)
		{
			swap_nodes(tail->prev, tail);
			if (tail->prev == NULL)
				*list = tail;
			print_list(*list);
		}
		else
			tail = tail->prev;
		if (tail->prev == NULL)
			head = tail;
	}
	return (head);
}


/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order
 * @list: pointer to the head of the list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail = NULL, *head = NULL, *len = NULL;
	int count = 0, n = 0;

	if (list == NULL || *list == NULL)
		return;
	*head = *list;
	*len = *list;

	for (count = 0; len != NULL; count++)
		len = len->next;

	if (count < 2)
		return;

	while (n < count)
	{
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(head, head->next);
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
			}
			else
				head = head->next;
			if (head->next == NULL)
				tail = head;
		}
		head = reverse(head, tail, list);
		*list = head;
		n++;
	}
}
