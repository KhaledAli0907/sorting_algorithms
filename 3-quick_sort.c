#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - partitions an array using the Lomuto scheme
 * @array: the array to be partitioned
 * @size: the size of the array
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 * Return: the final index of the pivot
 */
int partition(int *array, size_t size, int low, int high)
{
    int pivot, i, j;

    pivot = array[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (array[i + 1] > pivot)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quick_sort_helper - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 */
void quick_sort_helper(int *array, size_t size, int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(array, size, low, high);
        quick_sort_helper(array, size, low, p - 1);
        quick_sort_helper(array, size, p + 1, high);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, size, 0, size - 1);
}

