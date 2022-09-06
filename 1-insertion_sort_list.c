#include "sort.h"

/**
 *  
 * 
 * 
 */
void insertion_sort_list(listint_t **list)
{
	size_t len, i, j;
	listint_t *temp;
	listint_t *node = *list;

	while (*list != NULL)
	{
		len++;
		*list = *list->next;
	}

	while (j < len)
	{
		while (i < len)
		{
			if (node->next->n > node->n)
			{
				temp = node->n;
				node->n = node->next->n;
				node->next->n = temp;
				print_list(list);
			}
			i++;
		}
		i = 0;
		j++;
	}
}