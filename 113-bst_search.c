#include "binary_trees.h"
/**
 * bst_search - It searches for a special value in the
 * tree and return the node
 * @tree: The tree to evaluate
 * @value: The value to search
 * Return: node with the value or NULL if value is not in
 * the tree
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found;

	if (tree == NULL)
		return (NULL);
	if (value < tree->n)
	{
		found = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		found = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (found);
}
