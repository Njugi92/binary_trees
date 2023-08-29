#include "binary_trees.h"

/**
 * binary_tree_is_leaf - It determines if the node
 * is leaf meaning the node does not have any child
 * neither left nor right
 * @node: The node to survey
 * Return: Returns 1 if a leaf, 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}
	if (node->right == NULL && node->left == NULL)
	{
		return (1);
	}
	return (0);
}
