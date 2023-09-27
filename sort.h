#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element in the list
 * @next: Pointer to the next element in the list
 */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


void swap(int *a, int *b);
void print_array(int *a, int n);
size_t print_list(const listint_t *h);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif
