// https://leetcode.com/problems/reverse-linked-list-ii/
/* Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list. 
 */

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


struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(m>n || m<1)
        return head;
    struct ListNode *next, *pre=NULL, *cur=head, *mpre;
    int i;
    for(i=1; i<m && cur != NULL; i++){ // 移动m-1步，pre指向第m个节点
        pre=cur;
        cur = cur->next;
    }
    mpre = pre;
    struct ListNode *mnode=cur;  // 位置为 m 的那个节点
    for(i=m; i<=n && cur!=NULL; i++){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    if(mpre != NULL)
        mpre->next = pre;  // 解引用一个指针前一定检查是否为 NULL
    else
        head=pre;
    mnode->next = cur;
    return head;
}

void print(struct ListNode * node){
    while(node != NULL){
        printf("%d ", node->val);
        node=node->next;
    }
    printf("\n");
}

int main(){
    struct ListNode *list, *node1, *node2, *node4, *node3, *node5;
    node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val=1;
    node1->next = node2;
    node2->val=2;
    node2->next=node3;
    node3->val=3;
    node3->next=node4;
    node4->val=4;
    node4->next=node5;
    node5->val=5;
    node5->next=NULL;
    list=node1;
    print(list);
    print(reverseBetween(list, 1, 5));
    return 0;
}

