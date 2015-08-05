// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
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

// 在层序遍历的那道题上稍加修改
// 参考 levelOrder.cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> parent;
        queue<TreeNode *> child;
        vector<vector<int>> vvi;
        vector<int> buff; // 临时存放当前层的值
        auto *ptr_parent = &parent;
        auto *ptr_child = &child;
        int nlevel=1;
        if(root == nullptr)
            return vvi;
        ptr_parent->push(root);
        while(true){
            nlevel++;
            buff.clear();
            while(!ptr_parent->empty()){
                auto front = ptr_parent->front();
                ptr_parent->pop();
                if(front->left)
                    ptr_child->push(front->left);
                if(front->right)
                    ptr_child->push(front->right);
                buff.push_back(front->val);
            }
            if(!buff.empty()){
                if(nlevel % 2)
                    reverse(buff.begin(), buff.end());
                vvi.push_back(buff);
            }
            if(ptr_child->empty())
                break;
            // 交换两个指针
            auto tmp=ptr_parent;
            ptr_parent = ptr_child;
            ptr_child = tmp;
        }
        return vvi;
    }
};
