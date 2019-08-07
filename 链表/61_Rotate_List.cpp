/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL

Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL

Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k < 0)
            return NULL;
        int cnt = 0;
        ListNode* curNode = head;
        while(curNode){
            ++cnt;
            curNode = curNode->next;
        }
        k = k % cnt;
        if(k == 0)
            return head;
        curNode = head;
        for(int i = 1; i < cnt - k; ++i)
            curNode = curNode->next;
        ListNode* head1 = curNode->next;
        curNode->next = NULL;
        ListNode* curNode1 = head1;
        while(curNode1->next)
            curNode1 = curNode1->next;
        curNode1->next = head;
        return head1;
    }
};