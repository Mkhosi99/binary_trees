#include "binary_trees.h"
/**
 * minFinder - Finds the minimum root
 * @start: pointer to the tree
 * Return: the min number
 *
 * Time Complexity: O(h)
 */
bst_t *minFinder(bst_t *start)
{
	while (start->left != NULL)
		start = start->left;
	return (start);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 *
 * Time Complexity: O(h)
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tempo, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tempo = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tempo);
		}
		else if (root->right == NULL)
		{
			tempo = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tempo);
		}
		else
		{
			tempo = minFinder(root->right);
			root->n = tempo->n;
			root->right = bst_remove(root->right, tempo->n);
		}
	}
	return (root);
}
