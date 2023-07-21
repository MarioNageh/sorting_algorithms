#include "sort.h"

/**
 * swap - Swaps two integers
 * @i: The first integer to be swapped
 * @j: The second integer to be swapped
 */

void swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}
