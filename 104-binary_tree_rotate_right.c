#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree to the right
 * @tree: pointer to head of node to rotate
 * Return: pointer to the node to be rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	pivot = tree->left;
	tmp = pivot->right;
	pivot->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;

	if (tmp != NULL)
	{
		if (tmp->right == tree)
			tmp->right = pivot;
		else
			tmp->left = pivot;
	}
	return (pivot);
}
