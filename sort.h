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
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t **a, listint_t **b);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void siftDown(int *array, size_t index, size_t max);
void quick_sort_hoare(int *array, size_t size);

#endif
