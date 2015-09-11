// https://leetcode.com/problems/intersection-of-two-linked-lists/
//
/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

struct ListNode *getIntersectionNode(struct ListNode *headA, 
        struct ListNode *headB) {
    struct ListNode *pa=headA, *pb=headB;
    int lenA=0, lenB=0;
    if(headA == NULL || headB == NULL)
        return NULL;
    while(pa != NULL){
        lenA++;
        pa = pa->next;
    }
    while(pb != NULL){
        lenB++;
        pb = pb->next;
    }
    pa=headA;
    pb=headB;
    if(lenA > lenB){
        for(int i=0; i<lenA-lenB; i++)
            pa=pa->next;
    }else
        for(int i=0; i<lenB-lenA; i++)
            pb=pb->next;
    while(pa != pb && pa != NULL && pb != NULL){
        pa = pa->next;
        pb = pb->next;
    }
    return pa;
}


    

}
