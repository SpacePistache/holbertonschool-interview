#include <stdio.h>
#include "search_algos.h"

/**
 * print_subarray - Prints the part of the array being searched
 * @array: The array
 * @left: Index of the first element to print
 * @right: Index of the last element to print
 */
static void print_subarray(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
		printf("%d%s", array[i], i < right ? ", " : "\n");
}

/**
 * search_rec - Recursively searches for the first occurrence of a value
 * @array: The sorted array
 * @left: Index of the first element of the subarray
 * @right: Index of the last element of the subarray
 * @value: The value to search for
 *
 * Return: Index of the first occurrence of @value, or -1 if not found
 */
static int search_rec(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_subarray(array, left, right);
	mid = left + (right - left) / 2;

	if (array[mid] < value)
		return (search_rec(array, mid + 1, right, value));
	if (array[mid] == value && (mid == left || array[mid - 1] != value))
		return ((int)mid);
	if (left == right)
		return (-1);
	return (search_rec(array, left, mid, value));
}

/**
 * advanced_binary - Searches for the first occurrence of a value
 * in a sorted array of integers using recursive binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in @array
 * @value: The value to search for
 *
 * Return: Index of the first occurrence of @value,
 * or -1 if not present or if @array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (search_rec(array, 0, size - 1, value));
}
