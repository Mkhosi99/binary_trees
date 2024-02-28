#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  rotation on a tree
 * @tree: Pointer to
 *
 * Return: Pointer
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *chld, *parent = tree;

	if (!tree)
		return (NULL);

	chld = parent->left;
	if (!chld)
		return (tree);

	if (chld->right)
		chld->right->parent = parent;

	parent->left = chld->right;
	chld->right = parent;
	chld->parent = parent->parent;
	parent->parent = chld;

	if (chld->parent && chld->parent->left == parent)
		chld->parent->left = chld;
	else if (chld->parent)
		chld->parent->right = chld;

	return (chld);
}
