#include "sort.h"

/**
 * quick_sort - use the quick sort function
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}

/**
 * quick_sort_recursive - sorts and array recursively
 * @array: array to sort
 * @size: size of the array
 * @low: lowest position of the array
 * @high: highest position of the array
 * Return: void
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = partition(array, size, low, high);

		quick_sort_recursive(array, size, pivot + 1, high);

		quick_sort_recursive(array, size, low, pivot - 1);
	}
}

/**
 * partition - function that brakes the array
 * @array: array to brake
 * @size: size of the array
 * @low: lowest position of the array
 * @high: highest position of the array
 * Return: i + 1
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int j = 0;
	int i = (low - 1);

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			/* print_array(array, size); */
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * swap - swaps to integers
 * @a: integer one
 * @b: integer two
 * Return: 0
 */
int swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return (0);
}
