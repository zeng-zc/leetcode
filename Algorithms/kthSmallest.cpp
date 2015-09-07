// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

    Try to utilize the property of a BST.
    What if you could modify the BST node's structure?
    The optimal runtime complexity is O(height of BST).

    Credits:
    Special thanks to @ts for adding this problem and creating all test cases.
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
        vector<int> inorderTraversal(TreeNode* root) {
            stack<TreeNode *> stree;
            vector<int> vi;
            if(root==nullptr)
                return vi;
            while(true){
                for(; root; root=root->left)
                    stree.push(root);
                if(stree.empty())
                    break;
                root=stree.top();
                stree.pop();                
                vi.push_back(root->val);
                root = root->right;
            }
            return vi;
        }

        int kthSmallest(TreeNode* root, int k) {
            auto vi=inorderTraversal(root);
            return vi[k-1];
        }
};
