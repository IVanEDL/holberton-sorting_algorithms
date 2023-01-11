#include "sort.h"

/*
 * quick_sort - orders an array, quickly
 * @array: received array
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array && size > 0)
		quicksort_recursion(&array, 0, size - 1, size);
}

/*
 * swap - swaps elements of an array
 * @i: first element
 * @a: second element
 * @size: size of the array
 */

void swaper(int *array, size_t i, size_t a, size_t size)
{
	size_t temp;

	temp = array[a];
	array[a] = array[i];
	array[i] = temp;
	print_array(array, size);
}

/*
 * quicksort_recursion - truly orders an array
 * @array: array
 * @low: low
 * @high: high
 */

void quicksort_recursion(int **array, size_t low, size_t high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(*array, low, high, size);
		if (pivot == 0)
			pivot = high + 1;
		if (pivot == -1)
			return;
		quicksort_recursion(array, low, pivot - 1, size);
		quicksort_recursion(array, pivot + 1, high, size);
	}
}

/*
 * partition - does the windy thing
 * @array: array to partitionate
 * @low: atl
 * @high: PB
 * @size: size of the array
 * Return: index of the pivot
 */

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, a = low - 1, eq = 0;
	int pivot = array[high];

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			a++;
			if (array[a] != array[i])
				swaper(array, i, a, size);
		}
		if (array[i] == array[i + 1])
			eq++;
	}
	if (eq == size - 1)
		return - 1;
	if (array[high] != array[a + 1])
		swaper(array, high, a + 1, size);
	return (a + 1);
}
