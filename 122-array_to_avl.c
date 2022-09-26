#include "binary_trees.h"

/**
 * array_to_avl - converts an array into an avl
 * @array: array to be converted to avl
 * @size: size of the array
 * Return: avl_t an avl tree of the array
 */
avl_t *array_to_avl(int *array, size_t size)
{
  size_t i, j;
	
	avl_t *tree = NULL;
	if (array == NULL)
	  return (NULL);
	for (i = 0; i < size; i++)
	{
	  for (j = 0; j < i; j++)
	    {
	      if (array[j] == array[i])
		break;
	    }
	  if (j == i)
	    {
	      if (avl_insert(&tree, array[i]) == NULL)
		return (NULL);
	    }
	}
	return (tree);
}
