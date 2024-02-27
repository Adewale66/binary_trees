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
 * free_queue - frees a queue
 * @head: pointer to the head of the queue
 * Return: void
 */

void free_queue(queue *head)
{
	queue *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if not
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue *head = NULL;
	binary_tree_t *node;
	int flag = 0;

	if (!tree)
		return (0);
	insert_node(&head, (binary_tree_t *)tree);
	while (head)
	{
		node = pop_node(&head);
		if (node->left)
		{
			if (flag)
			{
				free_queue(head);
				return (0);
			}
			insert_node(&head, node->left);
		}
		else
			flag = 1;
		if (node->right)
		{
			if (flag)
			{
				free_queue(head);
				return (0);
			}
			insert_node(&head, node->right);
		}
		else
			flag = 1;
	}
	free_queue(head);
	return (1);
}
