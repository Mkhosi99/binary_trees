#include "binary_trees.h"

unsigned char isLeaf(const binary_tree_t *nde);
size_t isDepth(const binary_tree_t *b_tree);
const binary_tree_t *getLeaf(const binary_tree_t *b_tree);
int perfectRecursive(const binary_tree_t *b_tree,
		size_t leafDepth, size_t b_level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * isLeaf - Checks if a node is a leaf of a binary tree.
 * @nde: A pointer to the node to check.
 *
 * Return: If the node is a leaf return 1, otherwise return 0.
 */

unsigned char isLeaf(const binary_tree_t *nde)
{
	return ((nde->left == NULL && nde->right == NULL) ? 1 : 0);
}

/**
 * isDepth - Returns the depth of a given
 *           node in a binary tree.
 * @b_tree: A pointer to the node to measure the depth of
 *
 * Return: The depth of the node.
 */
size_t isDepth(const binary_tree_t *b_tree)
{
	return (b_tree->parent != NULL ? 1 + isDepth(b_tree->parent) : 0);
}

/**
 * getLeaf - Returns a leaf of a binary tree.
 * @b_tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *getLeaf(const binary_tree_t *b_tree)
{
	if (isLeaf(b_tree) == 1)
		return (b_tree);
	return (b_tree->left ? getLeaf(b_tree->left) : getLeaf(b_tree->right));
}

/**
 * perfectRecursive - Checks if a binary tree is perfect recursively.
 * @b_tree: A pointer to the root node of the tree to check.
 * @leafDepth: The depth of one leaf in the binary tree.
 * @b_level: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int perfectRecursive(const binary_tree_t *b_tree,
		size_t leafDepth, size_t b_level)
{
	if (isLeaf(b_tree))
		return (b_level == leafDepth ? 1 : 0);
	if (b_tree->left == NULL || b_tree->right == NULL)
		return (0);
	return (perfectRecursive(b_tree->left, leafDepth, b_level + 1) &&
			perfectRecursive(b_tree->right, leafDepth, b_level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (perfectRecursive(tree, isDepth(getLeaf(tree)), 0));
}
