#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  a left rotation
 * @tree: Pointerroot
 *
 * Return: Pointer  root
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *chld, *parent = tree;

	if (!tree)
		return (NULL);

	chld = parent->right;
	if (!chld)
		return (tree);

	if (chld->left)
		chld->left->parent = parent;

	parent->right = chld->left;
	chld->left = parent;
	chld->parent = parent->parent;
	parent->parent = chld;

	if (chld->parent && chld->parent->left == parent)
		chld->parent->left = chld;
	else if (chld->parent)
		chld->parent->right = chld;

	return (chld);
}
