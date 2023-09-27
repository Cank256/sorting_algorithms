#include "sort.h"

/**
 * lomuto_partition - Partitions the array using
 * the Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: The pivot index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1, j;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
int temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}

if (array[i + 1] != array[high])
{
int temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}

return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_idx = lomuto_partition(array, low, high, size);

quicksort(array, low, pivot_idx - 1, size);
quicksort(array, pivot_idx + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick Sort algorithm with Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
{
return;
}

quicksort(array, 0, size - 1, size);
}
