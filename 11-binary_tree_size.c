#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: If the tree is NULL, must return 0
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sze = 0;

	if (tree)
	{
		sze += 1;
		sze += binary_tree_size(tree->left);
		sze += binary_tree_size(tree->right);
	}
	return (sze);
}
