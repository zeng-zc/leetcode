//  https://leetcode.com/problems/sum-of-left-leaves/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root || (!root->left && !root->right))
        return 0;
    int rightsum = sumOfLeftLeaves(root->right);
    struct TreeNode* left = root->left;
    if (left && !left->left && !left->right)
        return root->left->val + rightsum;
    else
        return sumOfLeftLeaves(root->left) + rightsum;
    
}


// 定义辅助函数，更方便做递归
// 解法二
{
int helper(struct TreeNode* root, bool isleft);
int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root)
        return 0;
    return helper(root->left, true) + helper(root->right, false);
    
}

int helper(struct TreeNode* root, bool isleft) {
    if (!root)
        return 0;
    if (!root->left && !root->right && isleft) {
        return root->val;
    }
    return helper(root->left, true) + helper(root->right, false);
}
}


// 如果用C++来实现，连辅助函数都不用了，直接用函数的默认参数
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isleft=false) {
    if (!root)
        return 0;
    if (!root->left && !root->right && isleft) {
        return root->val;
    }
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
