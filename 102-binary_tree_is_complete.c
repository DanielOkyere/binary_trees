#include "binary_trees.h"

/**
 * createQueue - creates a queue for checking nodes
 * @front: front of the queue
 * @rear: rear of the queue
 * Return: pointer to pointer of queue
 */
const binary_tree_t **createQueue(int *front, int *rear)
{
	const binary_tree_t **queue = (const binary_tree_t **)malloc(
	    sizeof(binary_tree_t *) * MAX_Q_SIZE);

	*front = *rear = 0;
	return (queue);
}

/**
 * enQueue - puts node and rear in queue
 * @queue: pointer to pointer of queue
 * @new_node: pointer to binary tree new node
 * @rear: pointer to rear of binary tree
 */
void enQueue(const binary_tree_t **queue,
	     int *rear,
	     const binary_tree_t *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

/**
 * deQueue - removes from queues
 * @queue: pointer to pointer of the queue
 * @front: pointer to front of queue
 * Return: binary_tree_t;
 */
const binary_tree_t *deQueue(const binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * isQueueEmpty - checks if queue is empty
 * @front: front of the queue
 * @rear: rear of the queue
 * Return: int 1 if true, 0 if false
 */
int isQueueEmpty(int *front, int *rear)
{
	if (*rear == *front)
		return (1);
	return (0);
}

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to the tree
 * Return: 1 if true, 0 if false;
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int rear, front;
	const binary_tree_t *temp;
	int flag = 0;

	const binary_tree_t **queue = createQueue(&front, &rear);

	if (tree == NULL)
		return (0);

	enQueue(queue, &rear, tree);
	while (!isQueueEmpty(&front, &rear))
	{
		temp = deQueue(queue, &front);
		if (temp->left)
		{
			if (flag == 1)
				return (0);
			enQueue(queue, &rear, temp->left);
		}
		else
			flag = 1;

		if (temp->right)
		{
			if (flag == 1)
				return (0);
			enQueue(queue, &rear, temp->right);
		}
		else
			flag = 1;
	}
	return (1);
}
