/*
 *  Given a linked list, determine if it has a cycle in it.
 *
 *  Follow up:
 *  Can you solve it without using extra space? 
 */

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

// 算法：使用一个 fast 指针和一个 slow 指针，
// fast一次走两步，slow一次走一步。
// 两者相遇，则有环；fast指针遇到 NULL，则无环。

#include "ListNode.h"
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast=head, *slow=head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return 1;
    }
    return 0;
}


// notes:
// 这个版本比前一个使用 set 的版本要优雅和简单。
