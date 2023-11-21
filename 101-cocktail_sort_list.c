#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @a: pointer to the first node
 * @b: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
    listint_t *prev_a, *next_b;

    prev_a = a->prev;
    next_b = b->next;

    if (prev_a != NULL)
        prev_a->next = b;
    else
        *list = b;

    if (next_b != NULL)
        next_b->prev = a;

    b->prev = prev_a;
    b->next = a;
    a->prev = b;
    a->next = next_b;

    print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current, *next, *prev;
    int swapped;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = *list;
    swapped = 1;

    while (swapped)
    {
        swapped = 0;

        /* Forward pass */
        while (current->next != NULL)
        {
            next = current->next;
            if (current->n > next->n)
            {
                swap_nodes(list, current, next);
                swapped = 1;
            }
            else
                current = current->next;
        }

        if (!swapped)
            break;

        swapped = 0;
        prev = current;

        /* Backward pass */
        while (current->prev != NULL)
        {
            prev = current->prev;
            if (current->n < prev->n)
            {
                swap_nodes(list, prev, current);
                swapped = 1;
            }
            else
                current = current->prev;
        }
    }
}
