#include "sort.h"

/**
 * shell_sort - Function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: The array to sort.
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t med = 1, i = 0, j = 0;
	int temp;

	if (!array || size == 0 || size < 2)
		return;

	while (med < size / 3)
		med = med * 3 + 1;

	if (size == 2)
	{
		if (array[0] > array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
			print_array(array, size);
		}
		print_array(array, size);
	}
	else
	{

		for (; med > 0; med = (med - 1) / 3)
		{
			for (i = med; i < size; i++)
			{
				temp = array[i];
				for (j = i; j >= med && array[j - med] > temp; j -= med)
				{
					array[j] = array[j - med];
				}
				array[j] = temp;
			}
			print_array(array, size);
		}
	}
}
