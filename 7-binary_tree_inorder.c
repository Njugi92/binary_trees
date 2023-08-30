#include "binary_trees.h"

/**
 * binary_tree_inorder - This prints element of tree using
 * inroder traversal
 * @tree: The tree to traverse
 * @func: The function to use
 * Return: Nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		func(tree->n);
		binary_tree_inorder(tree->left, func);
		binary_tree_inorder(tree->right, func);
	}
}