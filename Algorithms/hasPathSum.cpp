// https://leetcode.com/problems/path-sum/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归。
// 优先思考递归解法，如果没有，再去想迭代解法
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return false;
        if(root->left==nullptr && root->right==nullptr &&
                root->val == sum)
            return true;
        if(root->left && hasPathSum(root->left, sum - root->val))
            return true;
        if(root->right && hasPathSum(root->right, sum - root->val))
            return true;;
        return false;
    }
};

