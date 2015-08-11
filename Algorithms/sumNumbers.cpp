/* https://leetcode.com/problems/sum-root-to-leaf-numbers/
Given a binary tree containing digits from 0-9 only, each root-to-leaf path
could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 
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
    int sumNumbers(TreeNode* root) {
        auto vs = root2leafNumbers(root);
        int sum=0;
        for(auto it: vs)
            sum += stoi(it);
        return sum;
    }
    vector<string> root2leafNumbers(TreeNode *root){
        vector<string> res;
        if(root == nullptr)
            return res;
        if(root->left == nullptr && root->right == nullptr){ // leaf node
            res.push_back(to_string(root->val)); // C++11 required
            return res;
        }
        res = root2leafNumbers(root->left);
        for(auto it=res.begin(); it != res.end(); it++){
            it->insert(0, to_string(root->val));
        }
        auto rightRes = root2leafNumbers(root->right);
        for(auto it=rightRes.begin(); it != rightRes.end(); it++){
            it->insert(0, to_string(root->val));
        }
        res.insert(res.end(), rightRes.begin(), rightRes.end());
        return res;
    }

    /* The below version has bugs. Wring result for [1,0] input.
    vector<int> root2leafNumbers2(TreeNode *root){
        vector<int> res;
        if(root == nullptr)
            return res;
        if(root->left == nullptr && root->right == nullptr){ // leaf node
            res.push_back(root->val);
            return res;
        }
        res = root2leafNumbers2(root->left);
        for(auto it=res.begin(); it != res.end(); it++){
            *it = *it *10 + root->val;
        }
        auto tmp = root2leafNumbers2(root->right);
        for(auto it=tmp.begin(); it != tmp.end(); it++){
            *it = *it *10 + root->val;
        }
        res.insert(res.end(), tmp.begin(), tmp.end());
        return res;
    }

    int reverseInt(int x){ // turn 123 to 321
        int res = 0;
        do {
            int lowbit = x % 10;
            x = x/10;
            res = res * 10 + lowbit;
        }while(x != 0);
        return res;
    }
    */

};
