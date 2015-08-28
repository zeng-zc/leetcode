// https://leetcode.com/problems/binary-tree-paths/
/*  Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]
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

// recursion!
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr)
            return res;
        if(root->left==nullptr && root->right==nullptr){
            res.push_back(to_string(root->val)); // to_string: itoa in C
            return res;
        }
        res= binaryTreePaths(root->left);
        if(!res.empty()){
            for(auto it=res.begin(); it!=res.end(); it++){
                auto tmp = to_string(root->val) + "->";
                it->insert(0, tmp); // note string insert api! not 'it->insert(it->begin(), tmp)'
            }
        }
        auto resRight = binaryTreePaths(root->right);
        if(!resRight.empty()){
            for(auto it=resRight.begin(); it!=resRight.end(); it++){
                auto tmp = to_string(root->val) + "->";
                it->insert(0, tmp);
            }
        }
        res.insert(res.end(), resRight.begin(), resRight.end());
        return res;
    }
};
// accepted
