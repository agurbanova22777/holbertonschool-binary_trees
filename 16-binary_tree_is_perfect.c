#include "binary_trees.h"

/**
 * leaf_depth - Finds depth of the leftmost leaf
 * @tree: Pointer to root node
 *
 * Return: Depth
 */
static size_t leaf_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	while (tree && tree->left)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect - Checks if a binary tree is perfect (helper)
 * @tree: Pointer to current node
 * @depth: Expected leaf depth
 * @level: Current level
 *
 * Return: 1 if perfect, otherwise 0
 */
static int is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
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

	depth = leaf_depth(tree);
	return (is_perfect(tree, depth, 0));
}
