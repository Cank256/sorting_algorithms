#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly
 * linked list of integers in ascending order
 * using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *sorted = NULL;
listint_t *current = *list;

if (list == NULL || *list == NULL || (*list)->next == NULL)
{
return;
}
while (current != NULL)
{
listint_t *next = current->next;
if (sorted == NULL || sorted->n >= current->n)
{
current->next = sorted;
current->prev = NULL;
if (sorted != NULL)
{
sorted->prev = current;
}
sorted = current;
*list = current;
}
else
{
listint_t *temp = sorted;
while (temp->next != NULL && temp->next->n < current->n)
{
temp = temp->next;
}
current->next = temp->next;
if (temp->next != NULL)
{
temp->next->prev = current;
}
temp->next = current;
current->prev = temp;
}
print_list(*list);
current = next;
}
}
