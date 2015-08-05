// https://leetcode.com/problems/partition-list/
/*
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5. 
 */

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *ge_first=NULL, *ge_last=NULL, 
                    *cur=head, *pre=NULL;
    int moved=0;
    if(head == NULL)
        return head;
    for(; cur != NULL; cur=cur->next){
        moved=0;
        if(cur->val >= x){
            moved=1;
            if(ge_last == NULL)
                ge_first = ge_last = cur;
            else{
                ge_last->next = cur;
                ge_last = cur;
            }
            if(pre != NULL)
                pre->next = cur->next;
            else
                head = cur->next;
        }
        if(moved==0)
            pre=cur;
    }
    if(pre != NULL)
        pre->next = ge_first;
    else
        head=ge_first;
    if(ge_last != NULL)
        ge_last->next = NULL;
    return head;
}

/* notes:
 * 这道题逻辑虽然很简单，但在写代码的过程中有一些容易犯错的点，
 * 比如，在解引用指针前忘了判断指针是否为 NULL。这些特例情况
 * 很容易被忽略掉。比如，pre 可能为 NULL，这时候就应该用
 * head->next 来代替 pre->next; 再比如，ge_last 可能为 NULL，
 * 这对应于第一次遇到大于等于 x 的元素。
 * 如果始终记得“解引用前先检查是否为NULL”这条法则，这个程序
 * 就很容易写对。
 *
 * 还有一个要注意的点是，如果当前节点被删除了，则 pre 指针
 * 不要移动。
 */
