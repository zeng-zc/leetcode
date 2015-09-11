// https://leetcode.com/problems/palindrome-linked-list/
/*
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */


/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */
 struct ListNode {

     int val;

      ListNode *next;

      ListNode(int x) : val(x), next(nullptr) {}

 };

using namespace std;

#include <vector>
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            vector<int> vi;
            int len=0;
            if(head == nullptr)
                return true;  // 空链表当做真，leetcode 网站测试结果
            for(auto p=head; p!= nullptr; p=p->next){
                vi.push_back(p->val);
                len++;
            }
            //int i=0, j=len-1;
            for(int i=0, j=len-1; i<=j; i++, j--){
               if(vi[i] != vi[j])
                  return false;
            }
           return true; 
        }
};

