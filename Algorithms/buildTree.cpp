// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
/* 
 * Given preorder and inorder traversal of a tree, construct the binary tree.
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
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            if(preorder.size() == 0)
                return nullptr;
            auto val=preorder[0];
            auto root=new TreeNode(val);
            auto rootvalIn = find(inorder.begin(), inorder.end(), val);
            vector<int> leftIn(inorder.begin(), rootvalIn);
            auto leftsize = leftIn.size();
            vector<int> leftPre(preorder.begin()+1, preorder.begin()+1 + leftsize);
            vector<int> rightIn(rootvalIn+1, inorder.end());
            vector<int> rightPre(preorder.begin() + leftsize + 1, preorder.end());
            root->left = buildTree(leftPre, leftIn);
            root->right = buildTree(rightPre, rightIn);
            return root;
        }

};
// Memory Limit Exceeded
// Making the copy of vectors eats too many memory!

void printTree(TreeNode* root){
    if(root == nullptr)
        return;
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}


// Using index, avoiding making copies.
class Solution2 {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            auto len = preorder.size();
            //return buildTree_help(preorder, inorder, 0, len-1, 0, len-1);
            return buildTree_help2(preorder, inorder, 0, 0, len);
        }

        TreeNode* buildTree_help(vector<int>& preorder, vector<int>& inorder,
                int pBegInd, int pEndInd, int iBegInd, int iEndInd) {
            if(pEndInd < pBegInd)
                return nullptr;
            auto val=preorder[pBegInd];
            auto root=new TreeNode(val);
            auto rootvalIn = find(inorder.begin()+iBegInd, 
                    inorder.begin()+iEndInd, val);
            auto rootIndexIn = rootvalIn - inorder.begin();
            auto lenleft = rootIndexIn - iBegInd;
            root->left = buildTree_help(preorder, inorder, pBegInd+1, 
                    lenleft+pBegInd, iBegInd, rootIndexIn-1);
            root->right = buildTree_help(preorder, inorder, pBegInd+1+lenleft, pEndInd, 
                    rootIndexIn+1, iEndInd);
            return root;
        }

        // Simplify the api
        TreeNode* buildTree_help2(vector<int>& preorder, vector<int>& inorder,
                int pBegInd, int iBegInd, size_t len) {
            if(len<=0)
                return nullptr;
            auto val=preorder[pBegInd];
            auto root=new TreeNode(val);
            auto tmp = inorder.begin() + iBegInd;
            auto rootvalIn = find(tmp, tmp+len, val);
            auto rootIndexIn = rootvalIn - inorder.begin();
            auto lenleft = rootIndexIn - iBegInd;
            root->left = buildTree_help2(preorder, inorder, pBegInd+1, 
                    iBegInd, lenleft);
            root->right = buildTree_help2(preorder, inorder, pBegInd+1+lenleft, 
                    rootIndexIn+1, len-lenleft-1);
            return root;
        }

};
// OJ scores: 56ms

        // Simplify the api of buildTree_help
class Solution3 {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            auto len = preorder.size();
            return buildTree_help2(preorder, inorder, 0, 0, len);
        }

        TreeNode* buildTree_help2(vector<int>& preorder, vector<int>& inorder,
                int pBegInd, int iBegInd, size_t len) {
            if(len<=0)
                return nullptr;
            auto val=preorder[pBegInd];
            auto root=new TreeNode(val);
            auto tmp = inorder.begin() + iBegInd;
            auto rootvalIn = find(tmp, tmp+len, val);
            auto rootIndexIn = rootvalIn - inorder.begin();
            auto lenleft = rootIndexIn - iBegInd;
            root->left = buildTree_help2(preorder, inorder, pBegInd+1, 
                    iBegInd, lenleft);
            root->right = buildTree_help2(preorder, inorder, pBegInd+1+lenleft, 
                    rootIndexIn+1, len-lenleft-1);
            return root;
        }
};
// OJ scores: 56ms


int main(){
    vector<int> preorder{1, 2, 3, 4, 5, 6},
        inorder{3, 2, 4, 1, 5, 6};
    Solution2 s;
    auto res = s.buildTree(preorder, inorder);
    printTree(res);
    return 0;
}
