#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Moves a node down the heap until the max-heap
 * property is restored
 * @array: The array representing the heap
 * @size: Full size of the array (used for printing)
 * @root: Index of the node to sift down
 * @end: Index of the last element still part of the heap
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, largest;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		largest = root;

		if (array[largest] < array[child])
			largest = child;
		if (child + 1 <= end && array[largest] < array[child + 1])
			largest = child + 1;
		if (largest == root)
			return;

		swap_ints(&array[root], &array[largest]);
		print_array(array, size);
		root = largest;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the sift-down heap sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;

	if (array == NULL || size < 2)
		return;

	/* Build a max heap, starting from the last parent node */
	start = (size - 2) / 2;
	while (1)
	{
		sift_down(array, size, start, size - 1);
		if (start == 0)
			break;
		start--;
	}

	/* Move the max to the end, shrink the heap, restore it */
	for (end = size - 1; end > 0; end--)
	{
		swap_ints(&array[0], &array[end]);
		print_array(array, size);
		sift_down(array, size, 0, end - 1);
	}
}
