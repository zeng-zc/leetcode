// https://leetcode.com/problems/binary-tree-inorder-traversal/

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

#include <stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vi;
        if(root==nullptr)
            return vi;
        vi = inorderTraversal(root->left);
        vi.push_back(root->val);
        vector<int> tmp;
        tmp = inorderTraversal(root->right);
        vi.insert(vi.end(), tmp.begin(), tmp.end());
        return vi;
    }

    // iteration version
    vector<int> inorderTraversal_iter(TreeNode* root) {
        stack<TreeNode *> stree;
        vector<int> vi;
        if(root==nullptr)
            return vi;
        while(true){
            for(; root; root=root->left)
                stree.push(root);
            if(stree.empty())
                break;
            root=stree.top(); // 调用 top 前，得保证栈非空，否则runtime error。
            stree.pop();
            vi.push_back(root->val);
            root = root->right;
        }
        return vi;
    }

};

/*notes:
 * C++ 新手容易犯的错误：
 * (1)vi.end() 忘记括号。注意这是一个函数调用。
 * (2) 栈调用 top() 和 pop() 之前，忘记检查栈是否为空。就跟解引用
 *     指针前不检查指针是否为NULL一样。
 */
