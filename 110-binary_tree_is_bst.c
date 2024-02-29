#include "binary_trees.h"

/**
 * bst - Compare node in order to check if a given
 *
 * @b_tree: pointer to the root node of the tree to check
 * @b_min: min value
 * @b_max: max value
 * Return: 1 if success, 0 otherwise
 *
 * Time Complexity: O(n)
 */
int bst(const binary_tree_t *b_tree, int b_min, int b_max)
{
	if (b_tree == NULL)
		return (1);

	if (b_tree->n < b_min || b_tree->n > b_max)
		return (0);

	return (
		bst(b_tree->left, b_min, b_tree->n - 1) &&
		bst(b_tree->right, b_tree->n + 1, b_max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search tree
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if success, 0 otherwise
 *
 * Time Complexity: O(n)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst(tree, INT_MIN, INT_MAX));
}
