#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the left child
 * @parent: parent node
 * @value: value to be inserted
 * Return: Pointer to the node or null
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tree;

	if (parent == NULL)
		return (NULL);

	tree = binary_tree_node(parent, value);
	if (tree == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		tree->right = parent->right;
		parent->right->parent = tree;
	}
	parent->right = tree;
	return (tree);
}
