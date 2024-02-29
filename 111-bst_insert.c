#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 *
 * Time Complexity: O(log(n)
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_val, *tree2;

	if (tree == NULL || *tree == NULL)
	{
		new_val = binary_tree_node(NULL, value);
		*tree = new_val;
		return (new_val);
	}

	tree2 = *tree;

	while (tree2 != NULL)
	{
		if (tree2->n == value)
			return (NULL);
		if (tree2->n > value)
		{
			if (tree2->left == NULL)
			{
				tree2->left = binary_tree_node(tree2, value);
				return (tree2->left);
			}
			tree2 = tree2->left;
		}
		if (tree2->n < value)
		{
			if (tree2->right == NULL)
			{
				tree2->right = binary_tree_node(tree2, value);
				return (tree2->right);
			}
			tree2 = tree2->right;
		}
	}
	return (NULL);
}
