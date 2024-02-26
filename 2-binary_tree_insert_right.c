#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: value is the value to store in the new node
 *
 * Return: a pointer to the created node, or NULL on failure
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNde;

	if (parent == NULL)
		return (NULL);

	newNde = binary_tree_node(parent, value);
	if (newNde == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		newNde->right = parent->right;
		parent->right->parent = newNde;
	}
	parent->right = newNde;
	return (newNde);
}
