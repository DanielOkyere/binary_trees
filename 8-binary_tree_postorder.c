#include "binary_trees.h"

/**
 * binary_tree_postorder - postorder traversal of binary tree
 * @tree: tree to be traversed
 * @func: Pointer to function call
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
