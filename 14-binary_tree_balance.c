#include "binary_trees.h"

/**
 * subtree_height - Measures height of a binary tree (helper)
 * Height is the number of edges on the longest path to a leaf.
 * @tree: Pointer to the root node of the tree to measure height
 *
 * Return: Height, or 0 if tree is NULL
 */
static size_t subtree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = subtree_height(tree->left);
	right = subtree_height(tree->right);

	if (tree->left)
		left++;

	if (tree->right)
		right++;

	return (left > right ? left : right);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)subtree_height(tree->left) - (int)subtree_height(tree->right));
}
