#include "sort.h"

/**
 * print_list - Prints all the elements of a listint_t list.
 * @h: A pointer to the listint_t list.
 *
 * Return: The number of nodes.
 */
size_t print_list(const listint_t *h)
{
size_t count = 0;

while (h != NULL)
{
printf("%d", h->n);
if (h->next != NULL)
{
printf(", ");
}
else
{
printf("\n");
}
count++;
h = h->next;
}

return (count);
}
