//https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vi;
        if(root==nullptr)
            return vi;
        vector<int> left = postorderTraversal(root->left);
        vi.insert(vi.end(), left.begin(), left.end());
        vector<int> right = postorderTraversal(root->right);
        vi.insert(vi.end(), right.begin(), right.end());
        vi.push_back(root->val);
        return vi;
    }

// 后序遍历的非递归版本比较难，这里参考了这篇文章：
// http://www.cnblogs.com/dolphin0520/archive/2011/08/25/2153720.html 
    vector<int> postorderTraversal_iter(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> vi;
        if(root==nullptr)
            return vi;
        TreeNode *cur, *pre=nullptr;
        st.push(root);
        while(!st.empty()){
            cur=st.top();
            if( (cur->left==nullptr && cur->right==nullptr)||
                    (pre!=nullptr &&
                     (pre==cur->left || pre==cur->right)) ){
                vi.push_back(cur->val);
                st.pop();
                pre=cur;
            } else{
                if(cur->right != nullptr)
                    st.push(cur->right);
                if(cur->left != nullptr)
                    st.push(cur->left);
            }
        }
        return vi;
    }
// OJ score: 0ms.

    // iteration version2, implement the algorith on wiki
    // https://en.wikipedia.org/wiki/Tree_traversal
    vector<int> postorderTraversal_iter2(TreeNode* root) {
        TreeNode *lastNodeVisited=nullptr;
        stack<TreeNode *> stree;
        vector<int> vi;
        while(!stree.empty() || root != nullptr){
            if(root != nullptr){
                stree.push(root);
                root=root->left;
            }else{
                auto peekNode=stree.top();
                auto tmp=peekNode->right;
                if(tmp != nullptr && lastNodeVisited != tmp)
                    root=tmp;
                else{
                    vi.push_back(peekNode->val);
                    lastNodeVisited=stree.top();
                    stree.pop();
                }
            }
        }
        return vi;
    }
    // OJ score: 0ms.

};
