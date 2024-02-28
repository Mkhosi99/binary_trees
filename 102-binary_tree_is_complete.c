#include "binary_trees.h"

/**
 * countNdes - Counts the inside of a tree
 * @start: node
 *
 * Return: Number of nodes
 * Time Complexity: O(n)
 */

int countNdes(binary_tree_t *start)
{
	if (!start)
		return (0);

	return (1 + countNdes(start->left) + countNdes(start->right));
}

/**
 * complete - Checks if a tree is complete
 * @start: Pointer to tree's root
 * @idx: Index of the node been evaluated
 * @numb: number of trees nod
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 * Time Complexity: O(n)
 */
int complete(binary_tree_t *start, int idx, int numb)
{
	if (!start)
		return (0);

	if (idx >= numb)
		return (0);
	if (!start->left && !start->right)
		return (1);
	if (start->right && !start->left)
		return (0);
	if (start->left && !start->right)
		return (complete(start->left, idx * 2 + 1, numb));

	return (complete(start->left, idx * 2 + 1, numb) &&
			complete(start->right, idx * 2 + 2, numb));
}

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: Pointer to root
 *
 * Return: 1 if working and 0m if NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node;
	binary_tree_t *start;

	if (!tree)
		return (0);

	start = (binary_tree_t *)tree;
	node = countNdes(start);

	return (complete(start, 0, node));
}
