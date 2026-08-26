#include "search.h"

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

	node = list;

	/* Walk the express lane until we overshoot or run out of lane */
	while (node->express != NULL && node->express->n < value)
	{
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
	}

	prev = node;

	if (node->express != NULL)
	{
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
	}
	else
	{
		/* No express node left: the range ends at the last node */
		while (node->next != NULL)
			node = node->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, node->index);

	/* Linear scan of the narrowed range */
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
