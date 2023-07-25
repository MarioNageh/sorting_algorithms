#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int max, i, *count, sum, *tmp;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	sum = 0;

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	tmp = malloc(sizeof(int) * size);
	if (count == NULL || tmp == NULL)
		return;
	for (i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < (int)size; i++)
	{count[array[i]] += 1; }
	for (i = 0; i <= max; i++)
	{sum += count[i];
	count[i] = sum; }
	print_array(count, max + 1);
	for (i = 0; i < size; i++)
	{
		tmp[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}
	free(count);
	free(tmp);
}
