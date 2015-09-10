// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
Given inorder and postorder traversal of a tree, construct the binary tree.
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

/* Algorithm:
 * The last element of postorder is root node, then find it in inorder.
 * divide inorder into left part and right part.
 */
class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            auto len = inorder.size();
            return buildTree_help2(inorder, postorder, 0, 0, len);
        }

        TreeNode* buildTree_help2(vector<int>& inorder, vector<int>& postorder,
                int iBegInd, int pBegInd, size_t len) {
            if(len<=0)
                return nullptr;
            auto val=postorder[pBegInd + len -1];
            auto root=new TreeNode(val);
            auto tmp = inorder.begin() + iBegInd;
            auto rootvalIn = find(tmp, tmp+len, val);
            auto rootIndexIn = rootvalIn - inorder.begin();
            auto lenleft = rootIndexIn - iBegInd;
            root->left = buildTree_help2(inorder, postorder,  
                    iBegInd, pBegInd, lenleft);
            root->right = buildTree_help2(inorder, postorder, rootIndexIn+1, 
                    pBegInd+lenleft, len-lenleft-1);
            return root;
        }
};
// OJ scores: 60ms

