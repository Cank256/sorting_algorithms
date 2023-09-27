#include "sort.h"

/**
 * siftDown - Heapify the array by sifting down a node.
 * @array: The array to be sorted as a heap.
 * @index: The index of the node to sift down.
 * @max: The maximum index to consider for swapping.
 */
void siftDown(int *array, size_t index, size_t max)
{
size_t root = index;
size_t leftChild = 2 * root + 1;
int temp;

while (leftChild <= max)
{
size_t swapIndex = root;
size_t rightChild = leftChild + 1;

if (array[swapIndex] < array[leftChild])
{
swapIndex = leftChild;
}

if (rightChild <= max && array[swapIndex] < array[rightChild])
{
swapIndex = rightChild;
}

if (swapIndex == root)
{
return;
}

temp = array[root];
array[root] = array[swapIndex];
array[swapIndex] = temp;
root = swapIndex;
leftChild = 2 * root + 1;
}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
size_t i, j;
int k;

if (array == NULL || size <= 1)
{
return;
}

for (k = (size / 2) - 1; k >= 0; k--)
{
siftDown(array, k, size - 1);
}

for (i = size - 1; i > 0; i--)
{
int temp = array[0];
array[0] = array[i];
array[i] = temp;

siftDown(array, 0, i - 1);

printf("Step %zu: ", size - i);
for (j = 0; j < size; j++)
{
printf("%d", array[j]);
if (j < size - 1)
{
printf(", ");
}
}
printf("\n");
}
}
