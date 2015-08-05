// https://leetcode.com/problems/path-sum-ii/
/*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

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
    // 每条路径用一个 vector<int> 表示
    // 显然也是一个递归问题
    // 跟前一道题 Path Sum 很像。
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res_final;
        vector<vector<int>> res_left;
        vector<vector<int>> res_right;
        if(root==NULL)
            return res_final;
        if(root->left==NULL && root->right==NULL &&
                root->val == sum){
            vector<vector<int>> tmp= {{root->val}};
            return tmp;
        }
        if(root->left){
            res_left=pathSum(root->left, sum - root->val);
            for(int i=0; i<res_left.size(); i++){
                auto it=res_left[i].begin();
                res_left[i].insert(it, root->val);
            }
        }
        if(root->right){
            res_right=pathSum(root->right, sum - root->val);
            for(int i=0; i<res_right.size(); i++){
                auto it=res_right[i].begin();
                res_right[i].insert(it, root->val);
            }
        }
        // 合并两个子树的结果
        res_final.insert(res_final.end(), res_left.begin(), res_left.end());
        res_final.insert(res_final.end(), res_right.begin(), res_right.end());
        return res_final;
    }
};

/* notes:
 * C++ 新手易犯的一个错误：
 * vector 的 insert 函数的位置参数是迭代器类型，
 * 不能使用1、2这样的下标。
 */
