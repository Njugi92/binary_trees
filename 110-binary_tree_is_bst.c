#include "binary_trees.h"
/**
 * check_sub_tree_left - It checks if all
 * nodes are smaller than specified root
 * @node: The node in the tree to verify
 * condition
 * @max: The value to compare
 * Return: 1 if all nodes are smaller or
 * equal or 0 if not
 */
int check_sub_tree_left(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = check_sub_tree_left(node->left, max);
		right = check_sub_tree_left(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_right - It checks if all the nodes are
 * bigger than the specified root
 * @node: The node in the tree to verify condition
 * @min: The value to compare
 * Return: 1 if all is bigger or equal or 0 otherwise
 */
int check_sub_tree_right(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
		{
			return (0);
		}
		left = check_sub_tree_right(node->left, min);
		right = check_sub_tree_right(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - It says if a tree is bst or not
 * Process involves checking if the left node is smaller
 * than the root, then verify if the right node is greater than
 * the root.
 * After verify if if the left subtree has nodes smaller than the
 * root and the right subtree has bigger nodes than root
 * @tree: The node that point to the node to check
 * Return: 1 if BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int v = 0, left = 2, right = 2;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		v = check_sub_tree_left(tree->left, tree->n);
		if (v == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		v = check_sub_tree_right(tree->right, tree->n);
		if (v == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
