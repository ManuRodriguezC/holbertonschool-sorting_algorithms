#include "sort.h"

/**
 *
 *
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int temp;

	while (j < size)
	{
		while (i < (size -1))
		{
			if (array[i + 1] < array[i])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
			i++;
		}
		i = 0;
		j++;
	}
}
