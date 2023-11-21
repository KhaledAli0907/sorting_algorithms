#include "sort.h"

/**
 * bubble_sort - sorting an array in ascinding order
 * 
 * @array: array of ints
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size) {


size_t i = 0, j = 0;

bool swapped = false;

for (i = size - 1; i > 0; i--)
{
    for (j = 0; j < i; j++)
    {
        if (array[j] > array[j + 1])
        {
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;

            swapped = true;

            print_array(array, size);
        }
    }

    if (!swapped)
        break;
}
}
