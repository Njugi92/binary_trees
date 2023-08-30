#include "binary_trees.h"

/**
 * binary_tree_is_root - The function determines if a
 * node is root
 * @node: The node to exermine
 * Return: 1 if a root, 0 if not
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
