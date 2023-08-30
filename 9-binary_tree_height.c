#include "binary_trees.h"

/**
 * binary_tree_height - It measures the height of binary tree
 * @tree: The tree to go through
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? l + binary_tree_height(tree->left) : 0;
			r = tree->right ? l + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
	}
}
