#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor (left height - right height). If tree is NULL, 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + (int)binary_tree_height(tree->left) : 0;
	right_h = tree->right ? 1 + (int)binary_tree_height(tree->right) : 0;

	return (left_h - right_h);
}
