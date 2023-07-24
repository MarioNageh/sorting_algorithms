#include "sort.h"

/**
*swap - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * lomuto_partition - partitions an array of integers in ascending order
 * using the Lomuto partition algorithm
 * @array: array to be sorted
 * @first: lowest index of the array
 * @last: highest index of the array
 * @size: size of the array
 * Return: index of the pivot
 */
int lomuto_partition(int *array, int first, int last, size_t size)
{
	int pivot = array[last];
	int current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * quick_sort_rec - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to be sorted
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: void
*/
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}
