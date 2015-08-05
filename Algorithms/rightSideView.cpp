// https://leetcode.com/problems/binary-tree-right-side-view/
/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> parent;
        queue<TreeNode *> child;
        vector<int> vi;
        vector<int> buff; // 临时存放当前层的值
        auto *ptr_parent = &parent;
        auto *ptr_child = &child;
        if(root == nullptr)
            return vi;
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
                buff.push_back(front->val);
            }
            if(!buff.empty()){
                vi.push_back(buff.back());
            }
            if(ptr_child->empty())
                break;
            // 交换两个指针
            auto tmp=ptr_parent;
            ptr_parent = ptr_child;
            ptr_child = tmp;
        }
        return vi;
    }
};
