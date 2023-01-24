#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - function that sorts an array of integers
    *              in ascending order using the Radix sort algorithm
    * @array: array
    * @size: array's size
    * Return: void
    */

void radix_sort(int *array, size_t size)
{
    int i = 0, max = 0, exp = 1, *output = NULL;
    int count[10] = {0};

    if (array == NULL || size < 2)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (i = 0; i < (int)size; i++)
        if (array[i] > max)
            max = array[i];

    while (max / exp > 0)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;

        for (i = 0; i < (int)size; i++)
            count[(array[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = (int)size - 1; i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (i = 0; i < (int)size; i++)
            array[i] = output[i];

        print_array(array, size);
        exp *= 10;
    }
    free(output);
}