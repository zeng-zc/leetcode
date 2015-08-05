// https://leetcode.com/problems/maximum-depth-of-binary-tree/

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     struct TreeNode *left;

 *     struct TreeNode *right;

 * };

 */

int maxDepth(struct TreeNode *root)
{
    int tmp1, tmp2, max;
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        return maxDepth(root->right) + 1;
    if (root->right == NULL)
        return maxDepth(root->left) + 1;
    tmp1 = maxDepth(root->left);
    tmp2 = maxDepth(root->right);
    max = (tmp1 > tmp2) ? tmp1 : tmp2;
    return max + 1;
}

// 将上述版本优化
// 第一个版本中，第一个if语句其实已经包含了后面两个if语句.
int maxDepth2(struct TreeNode *root) {
    int tmp1, tmp2, max;
    if (root == NULL)
        return 0;
    tmp1 = maxDepth(root->left);
    tmp2 = maxDepth(root->right);
    max = (tmp1 > tmp2) ? tmp1 : tmp2;
    return max + 1;
}
