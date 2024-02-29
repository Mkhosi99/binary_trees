#include "binary_trees.h"

/**
 * btlvl - auxiliary level
 *
 * @b_tree: pointer to root
 * Return: integer with level
 *
 * Time Complexity: O(n)
 */
int btlvl(const binary_tree_t *b_tree)
{
	int hLeft, hRight;

	if (b_tree == NULL)
		return (0);
	if (b_tree->left == NULL && b_tree->right == NULL)
		return (1);
	hLeft = btlvl(b_tree->left);
	hRight = btlvl(b_tree->right);
	if (hLeft > hRight)
		return (hLeft + 1);
	else
		return (hRight + 1);
}

/**
 * btBalance - factor calculate
 *
 * @b_tree: pointer to root
 * Return: integer with factor
 *
 * Time Complexity: O(n)
 */
int btBalance(const binary_tree_t *b_tree)
{
	if (b_tree == NULL)
		return (0);

	return (btlvl(b_tree->left) - btlvl(b_tree->right));
}

/**
 * b_avl - Check level
 *
 * @b_tree: pointer to root
 * @mini: min value
 * @maxi: max value
 * Return: 1 if is AVL, 0 otherwise
 *
 * Time Complexity: O(n)
 */
int b_avl(const binary_tree_t *b_tree, int mini, int maxi)
{
	int balanceLeft, balanceRight, bal;

	if (b_tree == NULL)
		return (1);
	if (b_tree->n > maxi || b_tree->n < mini)
		return (0);
	bal = btBalance(b_tree);
	if (bal < -1 || bal > 1)
		return (0);
	balanceLeft = b_avl(b_tree->left, mini, b_tree->n - 1);
	balanceRight = b_avl(b_tree->right, b_tree->n + 1, maxi);
	if (balanceLeft == 1 && balanceRight == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (b_avl(tree, INT_MIN, INT_MAX));
}
