#include "binary_trees.h"

/**
 * biary_tree_insert_left - It adds a node in the left of
 * the parent, if it exists it moves down one level and
 * add the new node
 * @parent: The parent to the specified node
 * @value: This is the value of the node
 * Return: It returns NULL, if it fails or new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
