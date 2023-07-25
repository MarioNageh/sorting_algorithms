#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
    int gab, i, j, temp;

    for (gab = size / 3; gab > 0; gab /= 3)
    {
        for (i = gab; i < (int) size; i++)
        {
            temp = array[i];
            j = i - gab;

            while (j >= 0 && array[j] > temp)
            {
                array[j + gab] = array[j];
                j -= gab;
            }
            array[j + gab] = temp;
        }
        print_array(array, size);
    }
}
