/*Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5 
 */

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *pre=NULL, *cur=head, *next;
    int deleted;  // 一个flag，标记是否发生了删除事件。
    while(cur != NULL){
        deleted=0;
        next=cur->next;
        if(cur->val == val){
            deleted=1;
            if(pre != NULL)
                pre->next = next;
            else
                head = next;
            free(cur);  // 释放被删除的节点的空间
        }
        if(deleted == 0)
            pre=cur;    // 只有当没有发生删除事件时，才移动 pre 指针
        cur=next;
    }
    return head;
}


/* Notes:
 * 一个容易犯错的坑：每一步都无脑移动pre指针（写linked list算法的思维定势）
 * 如果当前节点被删除了，移动pre到当前节点是没有意义的，导致出错。
 * 这个错误，我调试了好几遍才把思路理清楚。
 */
