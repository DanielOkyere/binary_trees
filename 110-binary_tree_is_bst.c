#include "binary_trees.h"
#include "limits.h"

/**
 * bst_help - checks binary tree is valid
 * @tree: pointer to tree
 * @l: smallest node visited
 * @h: hightest node visited
 * Return: 1 if valid, 0 otherwise
 */
int bst_help(const binary_tree_t *tree, int l, int h)
{
	if (tree != NULL)
	{
		if (tree->n < l || tree->n > h)
			return (0);

		return (bst_help(tree->left, l, tree->n - 1) &&
			bst_help(tree->right, tree->n + 1, h));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if tree is a valid binary search
 * @tree: pointer to the roote node of the tree
 * Return: 1 if there is a valid bst, 0 if otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_help(tree, INT_MIN, INT_MAX));
}
