//https://leetcode.com/problems/reverse-linked-list/
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
 struct ListNode {
      int val;
      struct ListNode *next;
 };

// iterative version
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *next, *pre=NULL, *cur=head;
    while(cur != NULL){  // cur 表示当前要处理的节点
        next = cur->next;
        cur->next = pre;
        pre=cur;
        cur=next;
    }
    return pre;
}

// recursive version
struct ListNode* reverseList2(struct ListNode* head) {
    struct ListNode *next;
    if(head == NULL)
        return NULL;
    next = head->next;
    if(next == NULL)
        return head;
    else{
        head->next = NULL;
        struct ListNode *newhead = reverseList2(next);
        next->next = head;
        return newhead;
    }
}

void print(struct ListNode * node){
    while(node != NULL){
        printf("%d ", node->val);
        node=node->next;
    }
    printf("\n");
}

int main(){
    struct ListNode *list, *node1, *node2;
    node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val=1;
    node1->next = node2;
    node2->val=2;
    node2->next=NULL;
    list=node1;
    print(list);
//    print(reverseList(list));
    print(reverseList2(list));
    return 0;
}

