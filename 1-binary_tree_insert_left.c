#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child
 * @parent: parent node
 * @value: value to be inserted
 * Return: Pointer to the node or null
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tree;

	if (parent == NULL)
		return (NULL);

	tree = binary_tree_node(parent, value);
	if (tree == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		tree->left = parent->left;
		parent->left->parent = tree;
	}
	parent->left = tree;
	return (tree);
}
