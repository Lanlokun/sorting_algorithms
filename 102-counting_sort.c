#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * conting sort - function that sorts an array of integers
*  in ascending order using the Shell sort algorithm
* @array: array
* @size: array's size
* Return: void
*/

void counting_sort(int *array, size_t size)
{
    int *count = NULL, *output = NULL, max = 0, i = 0;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < (int)size; i++)
        if (array[i] > max)
            max = array[i];

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i]]++;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    print_array(count, max + 1);

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (i = 0; i < (int)size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}