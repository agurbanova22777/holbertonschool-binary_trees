#include "binary_trees.h"

/**
 * binary_tree_is_perfect_rec - Checks if a binary tree is perfect (helper)
 * @tree: Pointer to current node
 * @depth: Expected leaf depth
 * @level: Current level (root is 0)
 *
 * Return: 1 if perfect, otherwise 0
 */
static int binary_tree_is_perfect_rec(const binary_tree_t *tree,
	size_t depth, size_t level)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (binary_tree_is_perfect_rec(tree->left, depth, level + 1) &&
		binary_tree_is_perfect_rec(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, otherwise 0. If tree is NULL, returns 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = binary_tree_height(tree);
	return (binary_tree_is_perfect_rec(tree, depth, 0));
}
