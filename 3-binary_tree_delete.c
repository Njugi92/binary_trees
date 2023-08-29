#include "binary_trees.h"

/**
 * binary_tree_delete - It frees an entire tree using
 * recursion to free the node as the node left and right
 * are NULL
 * @tree: This is tree to free
 * Return: It returns nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}
}
