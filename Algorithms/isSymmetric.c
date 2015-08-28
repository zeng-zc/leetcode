// https://leetcode.com/problems/symmetric-tree/
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 下面写了两个版本。

// 算法1：
// 先将其中一颗子树翻转，然后比较两个子树是否相等。
// 这两个过程在之前都练过了。
bool isSameTree(struct TreeNode* p, struct TreeNode* q);
struct TreeNode* invertTree(struct TreeNode* root);

bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
        return true;
    struct TreeNode *left = invertTree(root->left);
    return isSameTree(left, root->right);
}



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

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)
        return NULL;
    struct TreeNode *tmp;
    tmp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp;
    return root;
}



/* notes:
 * 说下几种错误的算法：
 * （1）检查整棵树的中序遍历结果是否为回文。反例： [1,2,3,3,null,2,null]。
 * （2）左子树按照正常中序遍历，右子树按照“右-根-左”顺序遍历，然后检查
 *      两个结果是否一致。这个错误本质上跟上面的是一样的。
 */

// 上面的版本实际上遍历了两遍（一遍用于翻转，一遍用于比较）
// 下面写一个更加精简的版本，只遍历一遍，略去翻转操作。

bool compare_left_right(struct TreeNode *left, 
        struct TreeNode *right);
bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return 1;
    return compare_left_right(root->left, root->right);
}

bool compare_left_right(struct TreeNode *left, 
        struct TreeNode *right){
    if(left == NULL && right == NULL)
        return 1;
    if(left == NULL && right != NULL)
        return 0;
    if(left != NULL && right == NULL)
        return 0;
    if(left->val != right->val)
        return 0;
    return compare_left_right(left->left, right->right) &&
            compare_left_right(left->right, right->left);
}
