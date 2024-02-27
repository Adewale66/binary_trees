#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *temp, *temp2;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	temp = first->parent, temp2 = second->parent;
	if (first == temp2 || !temp || (!temp->parent && temp2))
		return (binary_trees_ancestor(first, temp2));
	else if (temp == second || !temp2 || (!temp2->parent && temp))
		return (binary_trees_ancestor(temp, second));
	return (binary_trees_ancestor(temp, temp2));
}
