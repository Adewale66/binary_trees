#include "binary_trees.h"

/**
 * insert_node - inserts a node in a queue
 * @head: pointer to the head of the queue
 * @node: pointer to the node to insert
 * Return: void
 */

void insert_node(queue **head, binary_tree_t *node)
{
	queue *new, *temp;

	new = malloc(sizeof(queue));
	if (!new)
		return;
	new->node = node;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

/**
 * pop_node - pops a node from a queue
 * @head: pointer to the head of the queue
 * Return: pointer to the node
 */

binary_tree_t *pop_node(queue **head)
{
	queue *temp;
	binary_tree_t *node;

	if (!*head)
		return (NULL);
	temp = *head;
	*head = temp->next;
	node = temp->node;
	free(temp);
	return (node);
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue *head = NULL;
	binary_tree_t *node;

	if (!tree || !func)
		return;
	insert_node(&head, (binary_tree_t *)tree);
	while (head)
	{
		node = pop_node(&head);
		func(node->n);
		if (node->left)
			insert_node(&head, node->left);
		if (node->right)
			insert_node(&head, node->right);
	}
}
