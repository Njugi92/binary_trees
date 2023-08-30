#include "binary_trees.h"
/**
 * binary_trees_ancestor - It checks an ancestor
 * @first: The first node
 * @second: The second node
 * Return: The ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *x, *y;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}
	
	x = first->parent;
	y = second->parent;
	if (x == NULL || first == y || (!x->parent && y))
	{
		return (binary_trees_ancestor(first, y));
	}
	else if (y == NULL || x == second || (!y->parent && x))
	{
		return (binary_trees_ancestor(x, second));
	}
	return (binary_trees_ancestor(x, y));
}
