#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *prev, *next;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        prev = current->prev;
        next = current->next;
        while (prev != NULL && current->n < prev->n)
        {
            prev->next = next;
            if (next != NULL)
                next->prev = prev;
            current->prev = prev->prev;
            current->next = prev;
            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;
            prev->prev = current;
            print_list(*list);
            prev = current->prev;
            next = current->next;
        }
        current = next;
    }
}

