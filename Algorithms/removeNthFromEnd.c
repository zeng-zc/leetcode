// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len=0;
    struct ListNode *p=head, *pre=NULL;
    if(n <1 )
        return head;
    for(; p != NULL; p=p->next)
        len++;
    // 被移除元素的下标为 len-n
    p=head;
    for(int i=0; i< len-n; i++, p=p->next)
        pre=p;
    // 循环结束后，p 指向被删除的元素
    if(pre != NULL)
        pre->next= p->next;
    else
        head = p->next;
    free(p);
    return head;
}

// 上面的是个 naiive 版本。
// 下面写个 one-pass 的版本。
//
// 快慢指针版本：快指针先于慢指针 n 步走，则快指针走到
// 终点是，慢指针就走到了待删除的节点。


struct ListNode* removeNthFromEnd2(struct ListNode* head, int n) {
    struct ListNode *fast=head, *slow=head, *pre=NULL;
    if(n <1 )
        return head;
    for(int i=0; i<n; i++){
        fast = fast->next;
    }
    while(fast != NULL){
        pre=slow;
        slow = slow->next;
        fast = fast->next;
    }
    // 快指针始终比慢指针领先n个节点（两者的下标差为n）。
    // while循环结束后，fast指向NULL（记为倒数第0个节点），
    // 则此时 slow 指向倒数第n个节点
    if(pre != NULL)
        pre->next= slow->next;
    else
        head = slow->next;
    return head;
}
