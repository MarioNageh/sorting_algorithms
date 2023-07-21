#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */


void bubble_sort(int *array, size_t size)
{
	int i, j;
	int n_swaps = 0;

	for (i = 0; i < (int)size; i++)
	{
		n_swaps = 0;
		for (j = 0; j < (int)size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				n_swaps += 1;
				swap(&array[j], &array[j + 1]);
				print_array(array, size);

			}
		}

		if (n_swaps == 0)
			return;
	}
}
