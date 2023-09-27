#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using Counting sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
    int max = array[0], i;
    size_t j;
    ssize_t k;
    int *output_array = malloc(size * sizeof(int));
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (array == NULL || size <= 1)
        return;

    /* Find the maximum element in the array */
    
    for (j = 1; j < size; j++) {
        if (array[j] > max) {
            max = array[j];
        }
    }

    /* Create a counting array and initialize it to 0 */
    
    if (counting_array == NULL) {
        return; // Allocation failed
    }
    for (i = 0; i <= max; i++) {
        counting_array[i] = 0;
    }

    /* Populate the counting array with frequencies */
    for (j = 0; j < size; j++) {
        counting_array[array[j]]++;
    }

    /* Modify the counting array to store the positions of elements in the output array */
    for (i = 1; i <= max; i++) {
        counting_array[i] += counting_array[i - 1];
    }

    /* Create the output array */
    
    if (output_array == NULL) {
        free(counting_array);
        return; // Allocation failed
    }

    /* Build the sorted output array */
    for (k = size - 1; k >= 0; k--) {
        output_array[counting_array[array[k]] - 1] = array[k];
        counting_array[array[k]]--;
    }

    /* Copy the sorted elements back to the input array */
    for (j = 0; j < size; j++) {
        array[j] = output_array[j];
    }

    /* Print the counting array (optional) */
    for (i = 0; i <= max; i++) {
        printf("%d ", counting_array[i]);
    }
    printf("\n");

    /* Free allocated memory */
    free(counting_array);
    free(output_array);
}
