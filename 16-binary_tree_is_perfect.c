#include "binary_trees.h"

/**
 * tdepth - finds the depth of node
 * @tree: pointer to head of tree
 * Return: int depth of tree
 */
int tdepth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * isPerfectRec - checks tree, depth and level if perfect
 * @tree: pointer to tree
 * @d: depth of tree
 * @level: level of tree
 * Return: 1 if true, 0 if false
 */
int isPerfectRec(const binary_tree_t *tree, int d, int level)
{

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		if (d == level + 1)
			return (1);
		else
			return (0);
	}
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (isPerfectRec(tree->left, d, level + 1) &&
		isPerfectRec(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - checks the binary tree if perfect
 * @tree: tree to be checked
 * Return: int 1 if perfect, 0 if not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = tdepth(tree);

	return (isPerfectRec(tree, d, 0));
}
