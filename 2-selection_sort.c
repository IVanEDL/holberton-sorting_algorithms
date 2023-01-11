#include "sort.h"
/**
 * selection_sort - sorting algorithm
 * @arr: array
 * @size: size of array
 */
void selection_sort(int *arr, size_t size)
{
	size_t i, j = 0, aux;
	int temp;

	if (arr == NULL)
		return;

	for (i = 0; i < size -1; i++)
	{
		aux = i;
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[aux])
			{
				aux = j;
			}
		}
		if (aux != i)
		{
			temp = arr[i];
			arr[i] = arr[aux];
			arr[aux] = temp;
			print_array(arr, size);
		}
	}
}
