// https://leetcode.com/problems/reverse-nodes-in-k-group/

/*  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 *  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 *  You may not alter the values in the nodes, only nodes itself may be changed.
 *
 *  Only constant memory is allowed.
 *
 *  For example,
 *  Given this linked list: 1->2->3->4->5
 *
 *  For k = 2, you should return: 2->1->4->3->5
 *
 *  For k = 3, you should return: 3->2->1->4->5 
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int len=0;
    struct ListNode *cur=head, *pre=NULL, *next;
    while(cur){
        pre = cur;
        cur = cur->next;
        len++;
    }
    if(len<k) 
        return head;
    cur=head, pre=NULL;
    for(int i=0; i<k && cur!=NULL; i++){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    struct ListNode *newhead = reverseKGroup(cur, k);
    head->next = newhead;
    return pre;
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
    print(reverseKGroup(list, 3));
    print(reverseKGroup(list, 2));
    return 0;
}

