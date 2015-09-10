 // https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

 /*
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

 /*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// O(n) space, improved version at the bottom.
class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            auto len=nums.size();
            if(len==0)
                return nullptr;
            int mid = len/2;
            auto root = new TreeNode(nums[mid]);
            vector<int> left(nums.begin(), nums.begin()+mid);
            vector<int> right(nums.begin()+mid+1, nums.end());  // exclude mid element.
            root->left = sortedArrayToBST(left);
            root->right = sortedArrayToBST(right);  
            return root;
        }

};
// Accepted.

// O(1) space. Pass into the index.
// Don't make a new vector, do it in place.
class Solution2 {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            int len=nums.size();
            int lastIndex = len-1;
            return sortedArrayToBST_helper(nums, 0, lastIndex);
        }

        TreeNode* sortedArrayToBST_helper(vector<int>& nums, 
                int begIndex, int lastIndex) {
            if(lastIndex < begIndex)
                return nullptr;
            int mid = begIndex + (lastIndex-begIndex)/2;
            auto root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBST_helper(nums, begIndex, mid-1);
            root->right = sortedArrayToBST_helper(nums, mid+1, lastIndex);  
            return root;
        }
};
