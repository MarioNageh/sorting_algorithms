#include "sort.h"

/**
 * selection_sort - Sorting Selection Sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 * Description: Selection sort algorithm
 */

void selection_sort(int *array, size_t size)
{
	int i, j, min, temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < (int)size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (i == min)
			continue;
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		print_array(array, size);
	}
}
