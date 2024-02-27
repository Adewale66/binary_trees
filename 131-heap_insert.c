#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;
	heap_t *temp = NULL;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	temp = *root;
	while (temp)
	{
		parent = temp;
		if (temp->n < value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	new_node->parent = parent;
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;
	return (new_node);
}
