/*
 *  Write a function to delete a node (except the tail) in a singly linked
 *  list, given only access to that node.
 *
 *  Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third
 *  node with value 3, the linked list should become 1 -> 2 -> 4 after calling
 *  your function. 
 */

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

void deleteNode(struct ListNode* node) {

    if(node == NULL || node->next == NULL)  // 解引用一个指针前先要保证不为NULL

        return;

    node->val=node->next->val;

    node->next = node->next->next;

}

// 这里是释放的下一个节点的内存，修改了当前节点的内容。
// 教科书中经常讲到的是，修改前一个节点的指针，然后释放当前节点的内存。
