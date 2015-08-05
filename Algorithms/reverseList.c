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
// 容易犯错的一个坑：
// 那个 while 循环很容易无脑写成 while(cur->next != NULL)，
// 这样的话，最后一个节点就没有被处理（即next指针没被修改）

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
    print(reverseList(list));
    return 0;
}

