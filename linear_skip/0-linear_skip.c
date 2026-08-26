#include "search.h"

/**
 * skip_lane - Walks the express lane to bracket the search range
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 * @start: Address to store the start of the range
 *
 * Return: Pointer to the end node of the range
 */
skiplist_t *skip_lane(skiplist_t *list, int value, skiplist_t **start)
{
	skiplist_t *node = list;

	while (node->express != NULL && node->express->n < value)
	{
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
	}

	*start = node;

	if (node->express != NULL)
	{
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
	}
	else
	{
		while (node->next != NULL)
			node = node->next;
	}

	return (node);
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *prev;

	if (list == NULL)
		return (NULL);

	node = skip_lane(list, value, &prev);

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, node->index);

	while (prev != NULL && prev->index <= node->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
