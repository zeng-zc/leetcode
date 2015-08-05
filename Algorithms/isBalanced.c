// https://leetcode.com/problems/balanced-binary-tree/

/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     struct TreeNode *left;

 *     struct TreeNode *right;

 * };

 */
int maxDepth(struct TreeNode *root) {
    int tmp1, tmp2, max;
    if (root == NULL)
        return 0;
    tmp1 = maxDepth(root->left);
    tmp2 = maxDepth(root->right);
    max = (tmp1 > tmp2) ? tmp1 : tmp2;
    return max + 1;
}

bool isBalanced(struct TreeNode* root) {
    if(root==NULL)
        return 1;
    int ldepth = maxDepth(root->left);
    int rdepth = maxDepth(root->right);
    if(abs(ldepth-rdepth) > 1)
        return 0;
    return isBalanced(root->left) && isBalanced(root->right);
}

// 上述版本不断的重复访问节点，效率较低，下面寻求更高效的解法。
/*
bool isBalanced2(struct TreeNode* root) {
    if(root==NULL)
        return 1;
}
*/
