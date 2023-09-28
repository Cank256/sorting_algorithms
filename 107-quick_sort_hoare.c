#include "sort.h"

int hoare_partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(array, i, j);
        printf("Swap: %d <--> %d\n", array[i], array[j]);
    }
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = hoare_partition(array, low, high);
        quick_sort(array, low, pi);
        quick_sort(array, pi + 1, high);
    }
}

void quick_sort_hoare(int *array, size_t size) {
    if (array == NULL || size <= 1)
        return;

    quick_sort(array, 0, size - 1);
}
