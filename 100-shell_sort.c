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
    int gab = 1, i, j, temp;

    if (array == NULL || size < 2)
        return;

    while (gab < (int) size / 3)
    {
        gab = gab * 3 + 1;
    }

    while (gab >= 1)
    {
        for (i = gab; i < (int) size; i++)
        {
            temp = array[i];
            j = i - gab;
            while (j >= 0 && array[j] > temp)
            {
                array[j + gab] = array[j];
                j = j - gab;
            }
            array[j + gab] = temp;
        }
        gab = gab / 3;
        print_array(array, size);
    }
}
