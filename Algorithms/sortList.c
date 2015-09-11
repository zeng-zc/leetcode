// https://leetcode.com/problems/sort-list/
/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

//使用 mergesort

#include "ListNode.h"
#include <stdlib.h>
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


struct ListNode* sortList(struct ListNode* head) {
    struct ListNode *fast=head, *slow=head, *slow_pre=NULL;
    if(head == NULL)
        return NULL;
    if(head->next == NULL) // 一个节点，不用排
        return head;
    while(fast != NULL && fast->next != NULL){
        slow_pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *l2 = slow;
    slow_pre->next = NULL;
    struct ListNode *sorted1 = sortList(head);
    struct ListNode *sorted2 = sortList(l2);
    struct ListNode *res = mergeTwoLists(sorted1, sorted2);
    return res;
}

/* notes: 
 * 已通过 leetcode。
 * 一个容易犯错的地方：slow 指向的节点是合并排序右半部分的第一个节点，
 * 引起slow 前面的那个link 应该被砍断，所以一个指针来保存前一个节点。
 * 我写第一遍时，为图方便，将slow 后面的link 砍断，这是不对的，比如
 * 只有两个节点时，陷入了死循环，因为两部分不均等。
 *
 * 另一个容易犯错的地方：只有一个节点时，要直接返回，这种边界情况
 * 容易被忘记（就是 sortList 函数的第二个if语句）。
 *
 * 觉得链表的 mergesort 比数组的 mergesort 要简单，对于数组，要设置
 * 哨兵元素。
 */
