#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 *
 * Time Complexity: O(n^2)
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t lenth;
	bst_t *tree = NULL;

	for (lenth = 0; lenth < size; lenth++)
		bst_insert(&tree, array[lenth]);

	return (tree);
}
