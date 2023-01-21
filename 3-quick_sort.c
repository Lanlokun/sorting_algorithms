#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * void quick_sort - Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */


void quick_sort(int *array, size_t size)
{
     int pivot, temp;
    size_t i, j;

    if (size < 2)
        return;

    pivot = array[size - 1];
    i = 0;
    j = 0;
    while (j < size - 1)
    {
        if (array[j] < pivot)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
        j++;
    }

    array[size - 1] = array[i];
    array[i] = pivot;

    print_array(array, size);
    quick_sort(array, i);
    quick_sort(array + i + 1, size - i - 1);

   

}