#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - Allocates a new AVL node
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * build_avl - Recursively builds an AVL tree from a sorted array slice
 * @array: Pointer to the first element of the array
 * @low: Lower index of the slice
 * @high: Upper index of the slice
 * @parent: Pointer to the parent of the node being created
 *
 * Return: Pointer to the root of the built subtree, or NULL on failure
 */
avl_t *build_avl(int *array, int low, int high, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (low > high)
		return (NULL);

	mid = low + (high - low) / 2;

	root = create_node(parent, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = build_avl(array, low, mid - 1, root);
	root->right = build_avl(array, mid + 1, high, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, 0, (int)size - 1, NULL));
}
