#include "sort.h"

/**
 * bubble_sort - The function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm.
 * @array: The array for to sort.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int temp;

	while (j < size)
	{
		while (i < (size - 1))
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
