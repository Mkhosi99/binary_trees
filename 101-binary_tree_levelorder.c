#include "binary_trees.h"

/**
 * binary_tree_heightAux -  a tree
 * @b_tree: Pointer to
 * Return: Trees
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_heightAux(const binary_tree_t *b_tree)
{
	size_t h_left = 0, h_right = 0;

	if (!b_tree)
		return (0);
	if (b_tree->left)
		h_left = 1 + binary_tree_heightAux(b_tree->left);
	if (b_tree->right)
		h_right = 1 + binary_tree_heightAux(b_tree->right);

	if (h_left > h_right)
		return (h_left);
	return (h_right);
}

/**
 * outpt_levelOrder - print each
 * @b_tree: pointer to thse
 * @b_level: level of the tree
 * @o_func: pointer to a  node
 * Return: void
 *
 * Time Complexity: O(n)
 */

void outpt_levelOrder(const binary_tree_t *b_tree, int b_level,
		void (*o_func)(int))
{
	if (!b_tree)
		return;

	if (b_level == 1)
		o_func(b_tree->n);
	else if (b_level > 1)
	{
		outpt_levelOrder(b_tree->left, b_level - 1, o_func);
		outpt_levelOrder(b_tree->right, b_level - 1, o_func);
	}
}

/**
 * binary_tree_levelorder - function that goes through a
 * binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 *
 * Time Complexity: O(n)
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int b_height = 0;
	int lenth = 1;

	if (!tree || !func)
		return;

	b_height = binary_tree_heightAux(tree) + 1;

	while (lenth <= b_height)
	{
		outpt_levelOrder(tree, lenth, func);
		lenth++;
	}
}
