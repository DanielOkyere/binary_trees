#include "binary_trees.h"

/**
 * bst_remove - removes a node from a binary search tree
 * @root: root of the tree
 * @value:  value of the node to be removed
 * If the node to be deleted has two children,
 * it must be replaces with its first `in-order successor`
 * Return: a pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_rc(root, root, value));
}

/**
 * bst_remove_rc - removes the node using a recursive method
 * @root: root of the binary search tree
 * @node: bst_t pointer to the node
 * @value: int value to be removed from the node
 * Return: Null if failed, pointer to the successor
 */
bst_t *bst_remove_rc(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_rc(root, node->left, value));
		return (bst_remove_rc(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_delete - deletes a node from the binary search tree
 * @root: root of the node to be deleted
 * @node: node to be deleted
 * Return: successor node or NULL
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *succ = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}


	/* Left child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	succ = inorder_successor(node->right);
	node->n = succ->n;

	return (bst_delete(root, succ));
}

/**
 * inorder_successor - utility function
 * @root: bst_t root node
 * Return: Node of inorder successor
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}
	return (root);
}
