#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: list
 * Return: void
 */


void cocktail_sort_list(listint_t **list)
{
    listint_t *tmp = NULL, *tmp2 = NULL;
    int flag = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (flag)
    {
        flag = 0;
        tmp = *list;
        while (tmp->next != NULL)
        {
            if (tmp->n > tmp->next->n)
            {
                tmp2 = tmp->next;
                tmp->next = tmp2->next;
                if (tmp2->next != NULL)
                    tmp2->next->prev = tmp;
                tmp2->prev = tmp->prev;
                if (tmp->prev != NULL)
                    tmp->prev->next = tmp2;
                else
                    *list = tmp2;
                tmp2->next = tmp;
                tmp->prev = tmp2;
                print_list(*list);
                flag = 1;
            }
            else
                tmp = tmp->next;
        }
        if (flag == 0)
            break;
        flag = 0;
        tmp = tmp->prev;
        while (tmp->prev != NULL)
        {
            if (tmp->n < tmp->prev->n)
            {
                tmp2 = tmp->prev;
                tmp->prev = tmp2->prev;
                if (tmp2->prev != NULL)
                    tmp2->prev->next = tmp;
                tmp2->next = tmp->next;
                if (tmp->next != NULL)
                    tmp->next->prev = tmp2;
                tmp2->prev = tmp;
                tmp->next = tmp2;
                print_list(*list);
                flag = 1;
            }
            else
                tmp = tmp->prev;
        }
    }
}