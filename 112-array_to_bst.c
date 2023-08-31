#include "binary_trees.h"
/**
 * array_to_bst - This turns array to a bst tree
 * @array: The array to turn to BST
 * @size:Its size of array
 * Return: BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t k = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; k < size; k++)
	{
		if (k == 0)
		{
			bst_insert(&root, array[k]);
		}
		else
		{
			bst_insert(&root, array[k]);
		}
	}
	return (root);
}
