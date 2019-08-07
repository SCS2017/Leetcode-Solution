/*
删除链表的倒数第k个节点
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        
        for(int i = 0; i < n + 1; ++i){
            q = q->next;
        }
        while(q!= NULL){
            p = p->next;
            q = q->next;
        }
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        
        ListNode* resNode = dummyHead->next;
        delete dummyHead;
        return resNode;
    }
};