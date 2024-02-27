#include "binary_trees.h"

/**
 * get_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * @level: level of the node
 * Return: the depth of the node
 */

size_t get_depth(const binary_tree_t *tree, size_t level)
{
	if (tree == NULL)
		return (level);
	return (get_depth(tree->parent, level + 1));
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: the depth of the node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return ((get_depth(tree, 0)) - 1);
}
