/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

// 链表的插入排序。

#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL)
        return NULL;
    struct ListNode *process, *cursor, *pre_cursor, *next,
        *pre_process;
    for(process=head->next, pre_process=head; 
            process != NULL; ){
        int moved=0;
        next = process->next;
        for(cursor = head, pre_cursor=NULL; 
                cursor != process;){ 
            if(process->val < cursor->val){
                moved=1;
                if(pre_cursor != NULL)
                    pre_cursor->next = process;
                else
                    head = process;
                process->next = cursor; // 插入新位置
                pre_process->next=next; // 处理旧位置
                break;
            }else{
                pre_cursor=cursor;
                cursor=cursor->next;
            }
        }
        if(moved==0) // 如果发生了移动事件，pre_process 不用变
            pre_process = process;
        process = next;
    }

    // 处理完了要封尾，不然成循环链表了
    // 注意此时 process 已经为 NULL 了，而 pre_process 成为了最后一个节点。
    pre_process->next=NULL;
    return head;
}

/*
 * notes:
 * 几点需要注意的：
 * （1）对于链表节点的删除，要维护一个 pre 指针，如果当前节点发生了删除事件，
 * pre 指针是不用改变的，所以需要一个 flag 变量来标记是否发生了删除事件；
 * （2）容易犯错的一个地方是：虽然节点已经被移走或删除了，但是没有改变 pre->next;
 * （3）还是那句老话：解引用一个指针前要先检查是否为 NULL；
 * （4）处理完了要记得封尾，这点太容易忘记了。
 * 另外，感觉链表的插入排序虽然逻辑简单，但是操作起来太多细节需要注意了，
 * 稍不注意就容易写错，感觉比 mergesort 要复杂不少。
 *
 */

/*
struct ListNode *insertionSortList2(struct ListNode *head) {
      struct ListNode *dummy = malloc(sizeof (struct ListNode));
      struct  ListNode *cur = head;
        while (cur != NULL) {
            struct ListNode *pre = dummy;
            while (pre->next != NULL && pre->next->val < cur->val) {
                pre = pre->next;
            }
            struct ListNode *temp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = temp;
        }
        return dummy->next;
}
*/
// 上面的这个版本在 leetcode 上是 runtime error，但在我本机上是可以工作的。



// for test
void print(struct ListNode * node){
    while(node != NULL){
        printf("%d ", node->val);
        node=node->next;
    }
    printf("\n");
}

int main(){
    struct ListNode *node1, *node2, *node3, *node4;
    node1 = (struct ListNode *)malloc(sizeof (struct ListNode));
    node2 = (struct ListNode *)malloc(sizeof (struct ListNode));
    node3 = (struct ListNode *)malloc(sizeof (struct ListNode));
    node4 = (struct ListNode *)malloc(sizeof (struct ListNode));
    node1->val=4;
    node1->next=node2;
    node2->val=3;
    node2->next=node3;
    node3->val=2;
    node3->next=node4;
    node4->val=1;
    node4->next=NULL;
    print(insertionSortList(node3));
    return 0;
}

