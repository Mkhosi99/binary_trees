#include "binary_trees.h"

/**
 *binary_tree_insert_left - inserts a node as the left-child of another node
 *@parent: a pointer to the node to insert the left-child in
 *@value: the value to store in the new node
 *
 * Return: a pointer to the created node
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNde;

	if (parent == NULL)
		return (NULL);

	newNde = binary_tree_node(parent, value);
	if (newNde == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newNde->left = parent->left;
		parent->left->parent = newNde;
	}
	parent->left = newNde;

	return (newNde);
}
