/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

// 使用 set 的方法很简单，第一个insert 失败的那个指针就是答案。
// 下面使用快慢指针的方法，优点是不使用额外存储。
// 更详细的解释可以参考：
// http://www.cnblogs.com/hiddenfox/p/3408931.html
#include "ListNode.h"
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast=head, *slow=head;
    int hascycle=0;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            hascycle=1;
            break;
        }
    }
    if(hascycle == 1){
        for(slow=head; slow != fast; slow=slow->next,
                fast=fast->next)
            ;
        return fast;
    }
    return NULL;
}


// 一次通过 leetcode。
