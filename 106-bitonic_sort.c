#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *bitonic - function that sorts an array of integers
    *              in ascending order using the Bitonic sort algorithm
    * @array: array
    * @size: array's size
    * @dir: direction
    * Return: void
    */


void bitonic_sort(int *array, size_t size)
{
    int i = 0, j = 0, k = 0, l = 0, aux = 0;
    int *output = NULL;

    if (array == NULL || size < 2)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (i = 0; i < (int)size; i++)
        output[i] = array[i];

    for (i = 2; i <= (int)size; i *= 2)
    {
        for (j = i / 2; j > 0; j /= 2)
        {
            for (k = 0; k < (int)size; k++)
            {
                l = k ^ j;
                if (l > k)
                {
                    if ((k & i) == 0 && output[k] > output[l])
                    {
                        aux = output[k];
                        output[k] = output[l];
                        output[l] = aux;
                    }
                    if ((k & i) != 0 && output[k] < output[l])
                    {
                        aux = output[k];
                        output[k] = output[l];
                        output[l] = aux;
                    }
                }
            }
        }
    }
    for (i = 0; i < (int)size; i++)
        array[i] = output[i];
    free(output);
}