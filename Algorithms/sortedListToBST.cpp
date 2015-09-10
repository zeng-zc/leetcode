// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
/*
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

// use fast and slow pointers to find the middle quickly.
// After calling this function, the list  has beened altered.
class Solution {
public:
        TreeNode* sortedListToBST(ListNode* head) {
            if(head == nullptr)
                return nullptr;
            ListNode *fast=head, *slow=head, *preSlow=nullptr;
            while(fast != nullptr && fast->next != nullptr){
                preSlow = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            if(preSlow == nullptr)
                head = nullptr;
            else
                preSlow->next = nullptr;
            auto root = new TreeNode(slow->val);
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);
            return root;
        }
};

