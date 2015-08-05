// https://leetcode.com/problems/binary-tree-preorder-traversal/
//
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vi;
        if(root==nullptr)
            return vi;
        vi.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vi.insert(vi.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right);
        vi.insert(vi.end(), right.begin(), right.end());
        return vi;
    }

 
    // 迭代版本（参考了Horowitz 的数据结构教材）
    vector<int> preorderTraversal_iter(TreeNode* root) {
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

// 迭代前序遍历的第2个版本：
// 对于每一个结点，右子树先入栈，左子树后入栈。
// 因此出栈顺序是反过来的。
// 这个版本在理解上更为直观。
// 操作栈的顺序：出栈，右入，左入；出栈，右入，左入...
// 栈的初始状态是根节点在栈里。
    vector<int> preorderTraversal_iter2(TreeNode* root) {
        stack<TreeNode *> stree;
        vector<int> vi;
        if(root==nullptr) // 注意后面的代码没有包含这种特殊情况。
            // 如果不确定后面的代码是否包含了这种特殊情况，保险的做法是保留。
            return vi;
        stree.push(root);
        while(!stree.empty()){
            TreeNode *tmp = stree.top();
            stree.pop();
            vi.push_back(tmp->val);
            if(tmp->right)
                stree.push(tmp->right);
            if(tmp->left)
                stree.push(tmp->left);
        }
        return vi;
    }
};
