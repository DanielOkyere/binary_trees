#include "binary_trees.h"

/**
 * theight - height of binary tree
 * @tree: pointer to node of tree
 * Return: int height of tree
 * *
 */
int theight(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (0);

	lh = theight(tree->left);
	rh = theight(tree->right);

	if (lh > rh)
		return (lh + 1);
	else
		return (rh + 1);
}

/**
 * printCurrentLevel - prints node at current level
 * @tree: pointer to treee
 * @level: level to print
 * @func: func call
 */
void printCurrentLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printCurrentLevel(tree->left, level - 1, func);
		printCurrentLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverses binary tree using level-rder traversal
 * @tree: pointer to tree
 * @func: function call for each node
 * Return: NULL if func or tree is NULL
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i;
	int h = theight(tree);

	if (tree == NULL || func == NULL)
		return;

	for (i = 0; i <= h; i++)
		printCurrentLevel(tree, i, func);
}
