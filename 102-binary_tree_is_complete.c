#include "binary_trees.h"
/**
 * new_node - This creates a new node in a linked list
 * @node: Its a pointer type node to be created
 * Return: node created
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->node = node;
	new->next = NULL;

	return (new);
}
/**
 * free_q - It frees a node at a linked list
 * @head: Node of linked list
 */
void free_q(link_t *head)
{
	link_t *tmp_node;

	while (head)
	{
		tmp_node = head->next;
		free(head);
		head = tmp_node;
	}
}
/**
 * _push - It pushes a node into the stack
 * @node: type pointer of the node of the tree
 * @headhead node in the stack
 * @tail: tail node in the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new;

	new = new_node(node);
	if (new == NULL)
	{
		free_q(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}
/**
 * _pop - It pos a node into the stack
 * @head: The head node in the stack
 */
void _pop(link_t **head)
{
	link_t *tmp_node;

	tmp_node = (*head)->next;
	free(*head);
	*head = tmp_node;
}
/**
 * binary_tree_is_complete - It checks if binary tree is complete
 * @tree: Pointer type of node tree
 * Return: 1 if complete, 0 is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
	{
		exit(1);
	}
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		_pop(&head);
	}
	return (1);
}
