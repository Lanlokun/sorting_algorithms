#include <stdlib.h>
#include <stdio.h>
#include "deck.h"
#include "sort.h"


/**
 * sort_deck - Sorts a deck of cards
    * @deck: Double pointer to the head of the deck
    */

void sort_deck(deck_node_t **deck)
{
    deck_node_t *current = *deck;
    deck_node_t *next = NULL;
    int swapped = 1;

    if (deck == NULL || *deck == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        current = *deck;

        while (current->next != NULL)
        {
            next = current->next;

            if (current->card->value[0] > next->card->value[0])
            {
                swap(current, next);
                swapped = 1;
            }
            else if (current->card->value[0] == next->card->value[0])
            {
                if (current->card->kind > next->card->kind)
                {
                    swap(current, next);
                    swapped = 1;
                }
            }
            current = current->next;
        }
    }
}

/**
 * swap - Swaps two nodes in a doubly linked list
    * @current: Pointer to the first node
    * @next: Pointer to the second node
    */

void swap(deck_node_t *current, deck_node_t *next)
{
    deck_node_t *temp = NULL;

    if (current->prev != NULL)
        current->prev->next = next;
    if (next->next != NULL)
        next->next->prev = current;

    temp = current->prev;
    current->prev = next;
    next->prev = temp;

    temp = current->next;
    current->next = next->next;
    next->next = temp;
}