#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    /* Calculate the initial gap using the Knuth sequence formula */
    gap = 1;
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Perform the Shell sort with decreasing gaps */
    while (gap > 0)
    {
        /* Sort the subarrays with the current gap */
        for (i = gap; i < size; i++)
        {
            /* Save the current element and its index */
            temp = array[i];
            j = i;

            /* Shift the elements that are greater than temp to the right */
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            /* Insert temp at its correct position */
            array[j] = temp;
        }

        /* Print the array after each gap iteration */
        print_array(array, size);

        /* Decrease the gap by a factor of 3 */
        gap /= 3;
    }
}
