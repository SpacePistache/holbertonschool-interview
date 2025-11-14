#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_node - function creating a binary tree node.
* @parent: Pointer to the parent of new_node.
* @value: The data stored in the node.
* return: A pointer to a new node.
**/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
	
	binary_tree_t *new_node;
	new_node = malloc(sizeof(struct binary_tree_s));

	if (new_node == NULL) 
		return NULL;
	
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;

}
