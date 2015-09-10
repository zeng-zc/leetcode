// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/*
 *  Given a sorted linked list, delete all duplicates such that each element
 *  appear only once.
 *
 *  For example,
 *  Given 1->1->2, return 1->2.
 *  Given 1->1->2->3->3, return 1->2->3. 
 */

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

// 这道题跟 removeElements(删除单链表的给定值节点) 那道题很像。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre, *cur, *next;
        int deleted=0;
        if(head  == nullptr)
            return nullptr;
        pre=head;
        cur=head->next;
        while(cur != nullptr){
            deleted=0;
            next=cur->next;
            if(cur->val == pre->val){
                deleted=1;
                pre->next = next;
                free(cur);
            }
            if(deleted==0)
                pre=cur;
            cur=next;
        }
        return head;
    }
};
