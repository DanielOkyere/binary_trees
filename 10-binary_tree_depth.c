#include "binary_trees.h"

/**
 * binary_tree_depth - determines the depth of binary tree
 * @tree: pointer to the tree
 * Return: size_t depth of the tree or 0 if tree is null
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
