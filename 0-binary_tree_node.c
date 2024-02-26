#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL if fails
 *
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNde;

	newNde = malloc(sizeof(binary_tree_t));
	if (newNde == NULL)
		return (NULL);
	newNde->n = value;
	newNde->parent = parent;
	newNde->left = NULL;
	newNde->right = NULL;

	return (newNde);
}
