#include "binary_trees.h"
/**
 * tree_is_perfect - This is the function that says
 * if the tree is perfect or not s it has to be of the
 * same quantity levels left and right, also each node
 * has to have two nodes or more
 * @tree: The tree to evaluate
 * Return: Returns 0 if it's not perfect or other number
 * that is the level of height
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + binary_tree_is_perfect(tree->left);
		r = 1 + binary_tree_is_perfect(tree->right);
		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return(l);
	}
	else
	{
		return (0);
	}
}
