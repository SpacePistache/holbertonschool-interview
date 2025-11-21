#include "binary_trees.h"
#include <stdlib.h>

heap_t *find_parent_for_insert(heap_t *root);
heap_t *bubble_up(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to heap root
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *node;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_parent_for_insert(*root);
	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = node;
	else
		parent->right = node;

	node = bubble_up(node);

	return (node);
}


/**
 * find_parent_for_insert - Finds the parent where the next node goes
 * using level-order traversal (BFS).
 *
 * @root: Pointer to heap root
 *
 * Return: Pointer to parent node
 */
heap_t *find_parent_for_insert(heap_t *root)
{
	heap_t **queue;
	int front = 0, back = 0;
	heap_t *node;

	queue = malloc(sizeof(heap_t *) * 2048);
	if (!queue)
		return (NULL);

	queue[back++] = root;

	while (front < back)
	{
		node = queue[front++];

		if (node->left == NULL || node->right == NULL)
		{
			free(queue);
			return (node);
		}

		queue[back++] = node->left;
		queue[back++] = node->right;
	}

	free(queue);
	return (NULL);
}


/**
 * bubble_up - Restores Max Heap order by swapping values upward
 *
 * @node: Newly inserted node
 *
 * Return: Pointer to the node after bubbling
 */
heap_t *bubble_up(heap_t *node)
{
	int tmp;

	while (node->parent != NULL && node->n > node->parent->n)
	{

		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;

		node = node->parent;
	}

	return (node);
}
