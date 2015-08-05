/* Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    int tmp1, tmp2, min;
    if(root==NULL)
        return 0;
    if(root->left == NULL)
        return minDepth(root->right)+1;
    if(root->right == NULL)
        return minDepth(root->left)+1;
    tmp1 = minDepth(root->left);
    tmp2 = minDepth(root->right);
    min = (tmp1 < tmp2) ? tmp1 : tmp2;
    return min+1;
}

// 无法像 maxDepth 那样再优化了。
