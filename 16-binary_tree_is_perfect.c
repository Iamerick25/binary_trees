#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 *@tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left_height = 0, right_height = 0;

		if (tree->right)
			right_height = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left_height = 1 + binary_tree_height(tree->left);
		if (left_height > right_height)
			return (left_height);
		else
			return (right_height);
	}
	else
		return (0);
}

/**
 * binary_tree_size - measures the size of a binary tree.
 *@tree: pointer to the root node of the tree to measure the size.
 * Return: if tree is NULL, must return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	{
		size_t left, right;

		left = binary_tree_size(tree->left);
		right = binary_tree_size(tree->right);
		return (1 + left + right);
	}
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 *@tree: pointer to the root node of the tree to check.
 * Return: if tree is NULL, function must return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, size = 0;

	if (!tree)
		return (0);
	height = binary_tree_height(tree);
	size = (1 << (height + 1)) - 1;
	if (size == binary_tree_size(tree))
		return (1);
	else
		return (0);
}
