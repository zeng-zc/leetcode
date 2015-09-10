// https://leetcode.com/problems/linked-list-cycle/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode *> sl;
        sl.insert(head);
        while(head != NULL){
            head = head->next;
            auto ret = sl.insert(head);
            if(ret.second == false)
                return true;
        }
        return false;
    }
};

// 该版本已通过 leetcode 系统。
// 但是该算法是个naiive 的版本，使用了额外的内存。
