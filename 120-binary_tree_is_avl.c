#include "binary_trees.h"
#include "limits.h"

/**
 * binary_tree_is_avl - checks a binary tree is an avl
 * @tree: node to the root of the binary tree
 * Return: 0 if false or 1 if true
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl - utilitiy for recursive check of nodes
 * @tree: node to root of tree
 * @lo: value of the smallest node
 * @hi: value of largest node
 * Return: int 0 if true, 1 if false
 */
int is_avl(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = avl_height(tree->left);
		rhgt = avl_height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl(tree->left, lo, tree->n - 1) &&
			is_avl(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * bheight - determines the height of the binary tree
 * @tree: node to the binary tree
 * Return: int height of the binary tree
 */
size_t avl_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree)
	{
		l = tree->left ? 1 + avl_height(tree->left) : 1;
		r = tree->right ? 1 + avl_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
