#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
    * shell_sort - function that sorts an array of integers
    *              in ascending order using the Shell sort algorithm
    * @array: array
    * @size: array's size
    * Return: void
    */


void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i = 0, j = 0;
    int aux = 0;

    if (array == NULL || size < 2)
        return;

    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {.
            aux = array[i];
            j = i;
            while (j >= gap && array[j - gap] > aux)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = aux;
        }
        gap = (gap - 1) / 3;
        print_array(array, size);
    }