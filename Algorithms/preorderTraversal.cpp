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
// OJ score: 0ms

 
    // 迭代版本（参考了Horowitz 的数据结构教材）
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stree;
        vector<int> vi;
        if(root==nullptr)
            return vi;
        while(true){
            for(; root; root=root->left){
                vi.push_back(root->val);
                stree.push(root);
            }
            if(stree.empty())
                break;
            root=stree.top(); // 调用 top 前，得保证栈非空，否则runtime error。
            stree.pop();
            root = root->right;
        }
        return vi;
    }
// OJ score: 4ms
// 每个结点都被访问了2次，一次是for循环，一次是出栈。
// 有点拖泥带水，代码也不是那么直观易懂。

// 迭代前序遍历的第2个版本：
// 对于每一个结点，先取值，然后右子树先入栈，左子树后入栈。
// 因此出栈顺序是反过来的。
// 这个版本在理解上更为直观。
// 操作栈的顺序：出栈，取值，右入，左入；出栈，取值，右入，左入...
// 栈的初始状态是根节点在栈里。
    vector<int> preorderTraversal_iter2(TreeNode* root) {
        stack<TreeNode *> stree;
        vector<int> vi;
        if(root==nullptr) // 注意后面的代码没有包含这种特殊情况。
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
// OJ score: 0ms
// 每个结点只被访问了一次。代码也更加清爽易懂。

// 下面是wiki的伪码实现 https://en.wikipedia.org/wiki/Tree_traversal
// 本质上跟上一个版本是等价的。上一个版本在每次循环的尾部都将左结点
// 入栈，然后循环开头又出栈，下面这个版本直接简化了这个过程。
// 因此少了一半的进栈出栈操作，效率更高。
    vector<int> preorderTraversal_iter3(TreeNode* root) {
        stack<TreeNode *> stree;
        vector<int> vi;
        while(!stree.empty() || root != nullptr){
            if(root != nullptr){
                vi.push_back(root->val);
                if(root->right)
                    stree.push(root->right);
                root = root->left;
            }else{
                root = stree.top();
                stree.pop();
            }
        }
        return vi;
    }
// OJ score: 0ms.

};
