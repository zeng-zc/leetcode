// https://leetcode.com/problems/same-tree/
/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     struct TreeNode *left;

 *     struct TreeNode *right;

 * };

 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL)
        return 1;
    if(p == NULL && q != NULL)
        return 0;
    if(p != NULL && q == NULL)
        return 0;
    if(p->val != q->val)
        return 0;
    if(!isSameTree(p->left, q->left))
        return 0;
    if(!isSameTree(p->right, q->right))
        return 0;
    return 1;
}
