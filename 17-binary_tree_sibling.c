#include "binary_trees.h"

/**
 * binary_tree_sibling - gets the binary sibling
 * @node: pointer to the node
 * Return: sibling of the node or null
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
