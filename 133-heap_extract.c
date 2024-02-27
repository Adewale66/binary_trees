#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */

int heap_extract(heap_t **root)
{
	heap_t *temp;
	int value;

	if (!root || !*root)
		return (0);
	value = (*root)->n;
	temp = *root;
	while (temp->left)
		temp = temp->left;
	(*root)->n = temp->n;
	if (temp->parent->right == temp)
		temp->parent->right = NULL;
	else
		temp->parent->left = NULL;
	free(temp);
	return (value);
}
