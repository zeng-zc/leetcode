// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
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

// 把上一题（层序遍历）的输出结果翻转一下然后输入。。
// 不过我怀疑出题者不是这个意思。。
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> parent;
        queue<TreeNode *> child;
        vector<vector<int>> vvi;
        vector<int> buff; // 临时存放当前层的值
        auto *ptr_parent = &parent;
        auto *ptr_child = &child;
        if(root == nullptr)
            return vvi;
        ptr_parent->push(root);
        while(true){
            buff.clear();
            while(!ptr_parent->empty()){
                auto front = ptr_parent->front();
                ptr_parent->pop();
                if(front->left)
                    ptr_child->push(front->left);
                if(front->right)
                    ptr_child->push(front->right);
                buff.push_back(front>val);
            }
            if(!buff.empty())
                vvi.push_back(buff);
            if(ptr_child->empty())
                break;
            // 交换两个指针
            auto tmp=ptr_parent;
            ptr_parent = ptr_child;
            ptr_child = tmp;
        }
        reverse(res.begin(), res.end()); // 要包含头文件<algorithm>
        return vvi;
    }
};
