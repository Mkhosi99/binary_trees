#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowes
 * @first: Pointer
 * @second: Pointer
 *
 * Return: Pointer
 * Time Complexity: O(n^2)
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *first_anc, *sec_anc;

	for (first_anc = first; first_anc; first_anc = first_anc->parent)
		for (sec_anc = second; sec_anc; sec_anc = sec_anc->parent)
			if (first_anc == sec_anc)
				return ((binary_tree_t *)first_anc);
	return (NULL);
}
