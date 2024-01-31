#include "binary_trees.h"

/*
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: The dept of a tree or 0 if tree is null
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dept = 0;

	if (tree == NULL)
	{
		return (0);
	}

	while (tree->parent != NULL)
	{
		dept++;
		tree = tree->parent;
	}

	return (dept);
}
