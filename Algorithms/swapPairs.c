// https://leetcode.com/problems/swap-nodes-in-pairs/
/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    // 下面处理2个及以上的节点
    struct ListNode *first=head, *tmp;
    tmp = swapPairs(head->next->next);
    first = head;
    head = first->next;
    head->next = first;
    first->next = tmp;
    return head;
}

/* notes:
 * 很好，一次通过leetcode。
 * 经典的recursion 思想。
 */
