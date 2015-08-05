/**
 *
 *  * Definition for singly-linked list.
 *
 *   * struct ListNode {
 *
 *    *     int val;
 *
 *     *     struct ListNode *next;
 *
 *      * };
 *
 *       */

// 跟前面那道删除链表倒数第n个节点的题差不多
// 用fast、slow指针法。
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *fast=head, *slow=head, *pre_slow=NULL,
                    *pre_fast=NULL;
    if(head==NULL)
        return head;
    int len=0;
    for(; fast != NULL; len++, fast=fast->next);
    k=k%len;
    if(k<1)
        return head;
    fast=head;
    for(int i=0; i<k; i++){
        pre_fast=fast;
        fast = fast->next;
    }
    while(fast != NULL){
        pre_slow=slow;
        slow = slow->next;
        pre_fast=fast;
        fast = fast->next;
    }
    // 快指针始终比慢指针领先n个节点（两者的下标差为n）。
    // while循环结束后，fast指向NULL（记为倒数第0个节点），
    // 则此时 slow 指向倒数第n个节点
    pre_fast->next = head;
    head = slow;
    if(pre_slow != NULL)
        pre_slow->next= NULL;
    else  // 此时k=链表长度，最后一个元素变为 pre-fast
        pre_fast->next= NULL;
    return head;
}

/*notes:
 * 按照题目的意思，输入参数 k 可能是任意的，因此程序应该对
 * 各种k做处理。事实上 leetcode 上的测试用例中有空链表和
 * k大于链表长度的情况。
 */


struct ListNode* rotateRight2(struct ListNode* head, int k) {
    int len=0;
    struct ListNode *p=head, *pre=NULL, *last;
    // The first pass
    if(head == NULL)
        return head;
    for(; p != NULL; p=p->next){
        pre=p;
        len++;
    }
    k=k%len;
    if(k <1 )
        return head;
    last=pre;

    // The second pass
    p=head;
    for(int i=0; i< len-k; i++, p=p->next)
        pre=p;

    last->next = head;
    head=p;
    if(pre != NULL)
        pre->next= NULL;
    else
        last->next = NULL;
    return head;
}
 
