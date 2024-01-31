#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of a binary tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (binary_tree_balance(tree->left) - binary_tree_balance(tree->right));
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of the binary tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t left_height = 0, right_height = 0;

        if (tree == NULL)
        {
                return (0);
        }

        if (tree->left == NULL && tree->right == NULL)
        {
                return (0);
        }

        if (tree->left)
        {
                left_height = binary_tree_height(tree->left) + 1;
        }
        else
        {
                left_height = 1;
        }
        if (tree->right)
        {
                right_height = binary_tree_height(tree->right) + 1;
        }
        else
        {
                right_height = 1;
        }
        return (left_height > right_height ? left_height : right_height);

}
