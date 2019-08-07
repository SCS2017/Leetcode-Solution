/*
请判断一个链表是否为回文链表。

示例 1:
输入: 1->2
输出: false

示例 2:
输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head,  *prev = NULL;
        while (fast){
            slow = slow->next;
            fast = fast->next ? fast->next->next: fast->next;
        }
        while (slow){
            ListNode* ovn = slow->next;
            slow->next = prev;
            prev = slow;
            slow = ovn;
        }
        while (head && prev){
            if (head->val != prev->val){
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }   
};
