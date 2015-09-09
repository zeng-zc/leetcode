// https://leetcode.com/problems/add-two-numbers/
/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 结点先分配后使用，如果没有元素填充结点，则回收。
// 由于有回溯过程，所以需要一个 pre 指针。
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int carry=0;
           // auto head= (ListNode*)malloc(sizeof(struct ListNode)); // 先分配后使用
            auto head = new ListNode(0); // C++ prefers new than malloc! malloc 不够安全。
                        // ListNode(0) 实际上在调用构造器。
            ListNode *cur=head, *pre=nullptr;
            while(l1 && l2){
                int val = l1->val + l2->val + carry;
                carry = val/10;
                val = val%10;
                cur->val = val;
                //auto node = (ListNode*)malloc(sizeof(struct ListNode));
                auto node = new ListNode(0); // C++ prefers new than malloc! malloc 不够安全。
                cur->next = node;
                pre = cur;
                cur = node;
                l1 = l1->next;
                l2 = l2->next;
            }
            // remained
            if(l1 == nullptr)
                l1 = l2;
            while(l1){
                int val = l1->val + carry;
                carry = val/10;
                val = val%10;
                cur->val = val;
                //auto node = (ListNode*)malloc(sizeof(struct ListNode));
                auto node = new ListNode(0); // C++ prefers new than malloc! malloc 不够安全。
                cur->next = node;
                pre = cur;
                cur = node;
                l1 = l1->next;
            }
            // 别忘了最后要处理一下进位！
            if(carry == 1){
                cur->val=1;
                cur->next=nullptr;
            }else{
                pre->next=nullptr;
                //free(cur); // 回收！
                delete cur;  // delete 搭配 new
            }
            return head;
        }
};
// Accepted.

// 上面的版本有点臃肿，下面写个干净的版本。
// 不再盲目创建结点，而是先判断。
// 下面用到了哨兵结点，如果不用哨兵结点的话，就要在循环里判断是否为首个结点了，
// 类似这样：
// if(head == nullptr)
//      head=node;
//
class Solution {  
    public:  
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {  
            int carry = 0;  
            ListNode head(0),*cur = &head;  //head 为哨兵结点
            cur->next = nullptr;  
            while(l1 || l2 || carry){  
                int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;  
                cur->next = new ListNode(val % 10); // new 会调用构造器，要提供初始值
                cur = cur->next;  
                carry = val / 10;  
                l1 = l1 ? l1->next : l1;  
                l2 = l2 ? l2->next : l2;  
            }  
            cur->next = nullptr;  // 封尾!
            return head.next;  
        }  
};
