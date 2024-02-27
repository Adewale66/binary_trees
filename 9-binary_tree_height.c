#include "binary_trees.h"

/**
 * max - returns the max of two numbers
 * @a: first number
 * @b: second number
 * Return: the max of a and b
 */

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * get_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

size_t get_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(get_height(tree->left), get_height(tree->right)));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (get_height(tree) - 1);
}
