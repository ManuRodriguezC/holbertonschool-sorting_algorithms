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

	if (!array || size == 0)
		return;

	for (med = med * 3 + 1; med > 0; med /= 3)
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
