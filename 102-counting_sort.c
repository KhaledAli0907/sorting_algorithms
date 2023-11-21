#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    size_t i, max, total;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array */
    max = array[0];
    for (i = 1; i < size; i++)
    {
        if ((size_t) array[i] > max)
            max = array[i];
    }

    /* Allocate memory for the count and output arrays */
    count = malloc(sizeof(int) * (max + 1));
    output = malloc(sizeof(int) * size);
    if (count == NULL || output == NULL)
    {
        free(count);
        free(output);
        return;
    }

    /* Initialize the count array to zero */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count the frequency of each element in the array */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Print the count array */
    printf("%d", count[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count[i]);
    printf("\n");

    /* Calculate the cumulative sum of the count array */
    total = 0;
    for (i = 0; i <= max; i++)
    {
        total += count[i];
        count[i] = total;
    }

    /* Place the elements in the output array according to the count array */
    for (i = 0; i < size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the output array to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free the allocated memory */
    free(count);
    free(output);
}
