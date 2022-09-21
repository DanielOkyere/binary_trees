#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the sibling of the parent of current
 * node
 * @node: pointer to node
 * Return: NULL if parent or uncle doesnt exist, uncle if exist
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
