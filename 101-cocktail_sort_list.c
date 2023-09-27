#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Cocktail Shaker sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        current = *list;

        while (current->next != NULL)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &(current->next));
                swapped = 1;
                print_list(*list);
            }
            else
            {
                current = current->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        while (current->prev != NULL)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &(current->prev), &current);
                swapped = 1;
                print_list(*list);
            }
            else
            {
                current = current->prev;
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to a pointer to the head of the list.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
    listint_t *temp_prev = (*a)->prev;
    listint_t *temp_next = (*b)->next;

    if (temp_prev != NULL)
        temp_prev->next = *b;
    else
        *list = *b;

    if (temp_next != NULL)
        temp_next->prev = *a;

    (*a)->prev = *b;
    (*a)->next = temp_next;
    (*b)->prev = temp_prev;
    (*b)->next = *a;
}
