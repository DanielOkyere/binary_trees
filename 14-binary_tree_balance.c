#include "binary_trees.h"

/**
 * bheight - custom binary height
 * @tree: pointer to tree
 * Return: height or 0
 */
size_t bheight(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + bheight(tree->left) : 1;
		r = tree->right ? 1 + bheight(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures if binary tree is balance
 * @tree: pointer to the binary tree
 * Return: 1 if true else 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (bheight(tree->left) - bheight(tree->right));

	return (0);
}
