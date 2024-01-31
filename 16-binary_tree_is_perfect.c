#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check if binary tree is perfect
 * @tree: pointer to the node
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (tree == NULL)
	{
		return (0);
	}
	height = binary_tree_is_full(tree) ? 1 : 0;
	size = binary_tree_balance(tree) == 0 ? 1 : 0;
	return (height && size ? 1 : 0);
}

/**
 * binary_tree_is_full - Check if binary tree is full
 * @tree: the pointer to the node
 * Return: 1 if full otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (recursive_full_check(tree));
}

/**
 * recursive_full_check - check if full recurisively
 * @tree: the pointer to the node
 * Return: 1 if full 0 otherwise
 */
int recursive_full_check(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    recursive_full_check(tree->left) == 0 ||
		    recursive_full_check(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_balance - Calculate the tree balance
 * @tree: the pointer to the tree
 * Return: balance factor or 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - calculate the height of a binary tree.
 * @tree: A pointer to the tree root node.
 * Return: height else 0 if tree is Null.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL) /* if node doesnt exist */
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	else
		left_height = 1;

	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;
	else
		right_height = 1;

	return (left_height > right_height ? left_height : right_height);
}
