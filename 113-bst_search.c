#include "binary_trees.h"

/**
 * bst_search - searches a binary tree for a value
 * @tree: pointer to the tree for search
 * @value: value to be searched fro
 * Return: pointer to node of value or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
