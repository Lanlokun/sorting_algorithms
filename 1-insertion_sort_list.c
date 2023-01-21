#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * void insertion_sort_list - Sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
    * @list: The list to be sorted
    */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next, *prev, *temp;

    if (list == NULL || *list == NULL)
        return;

    current = *list;
    while (current != NULL)
    {
        next = current->next;
        while (current->prev != NULL && current->n < current->prev->n)
        {
            prev = current->prev;
            temp = current->next;
            if (prev->prev != NULL)
                prev->prev->next = current;
            current->prev = prev->prev;
            current->next = prev;
            prev->prev = current;
            prev->next = temp;
            if (temp != NULL)
                temp->prev = prev;
            if (current->prev == NULL)
                *list = current;
            print_list(*list);
        }
        current = next;
    }
}