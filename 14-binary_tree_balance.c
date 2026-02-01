#include "binary_trees.h"

/**
 * height - Measures height of a binary tree (helper)
 * @tree: Pointer to root node
 *
 * Return: Height, 0 if NULL
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = tree->left ? 1 + height(tree->left) : 0;
	right_h = tree->right ? 1 + height(tree->right) : 0;

	return (left_h > right_h ? left_h : right_h);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor (left height - right height), or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = (int)height(tree->left);
	right_h = (int)height(tree->right);

	return (left_h - right_h);
}
