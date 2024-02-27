#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: If tree is NULL, must return 0
 *
 * Time Complexity: O(n)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_treeHeight(tree->left) - binary_treeHeight(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: if the tree is NULL, must return 0
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree)
	{
		left = (tree->left) ? 1 + binary_tree_height(tree->left) : 1;

		right = (tree->right) ? 1 + binary_tree_height(tree->right) : 1;
		return (left > right ? left : right);
	}
	return (0);
}
