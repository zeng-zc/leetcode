// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
//
/*
 *  Given a sorted linked list, delete all nodes that have duplicate numbers,
 *  leaving only distinct numbers from the original list.
 *
 *  For example,
 *  Given 1->2->3->3->4->4->5, return 1->2->5.
 *  Given 1->1->1->2->3, return 2->3. 
 */
/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode * dele_pre=NULL, *dele_end, 
                    *pre=NULL, *cur;
    if(head == NULL)
        return NULL;
    for(cur=head; cur != NULL &&cur->next!=NULL; ){
        dele_end=NULL;
        struct ListNode *del=cur;
        while(del->next != NULL && del->val == del->next->val){
            if(dele_end != NULL)
                dele_end = dele_end->next;
            else{
                dele_pre=pre;
                dele_end=del->next;
            }
            del=del->next;
        }
        if(dele_end != NULL){ // 是否发生了删除事件
            if(dele_pre != NULL){
                //            dele_beg = dele_pre->next;
                dele_pre->next = dele_end->next;
            }else{
                //            dele_beg = head;
                head=dele_end->next;
            } 
            cur = dele_end->next;
        } else {
            pre=cur;
            cur = cur->next;
        }

        // free the deleted nodes
        /*
        for(sturct ListNode *tmp=dele_beg; 
               tmp != NULL; tmp=tmp->next){
               }
        */
    }
    return head;
}


/* notes:
 * 虽然逻辑比较简单，但写代码的过程很容易出错。
 * （1）各种检查非NULL 指针；
 * （2）各种循环的截止条件
 */
