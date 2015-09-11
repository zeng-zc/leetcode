// https://leetcode.com/problems/merge-two-sorted-lists/
/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */
#include "ListNode.h"
struct ListNode* mergeTwoLists(struct ListNode* l1, 
        struct ListNode* l2) {
    struct ListNode* new, *cur; // new 新链表的表头，cur： new中已经就位的最后一个节点
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    if(l1->val <= l2->val){
        cur = new = l1;
        l1 = l1->next;
    } else {
        cur = new = l2;
        l2 = l2->next;
    }
    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if(l1 == NULL)
        cur->next = l2;
    else
        cur->next = l1;
    return new;
}


/* notes:
 * 很好，一次通过 leetcode。
 * 最重要的是把思路理清晰。
 */
