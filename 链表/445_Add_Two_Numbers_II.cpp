/*
给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。
将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶:

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

示例:

输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 8 -> 0 -> 7
*/


#include <iostream>
#include <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
首先遍历两个链表，将所有数字分别压入两个栈s1和s2中，我们建立一个值为0的res节点，然后开始循环，如果栈不为空，
则将栈顶数字加入sum中，然后将res节点值赋为sum%10，然后新建一个进位节点head，赋值为sum/10，
如果没有进位，那么就是0，然后我们head后面连上res，将res指向head，这样循环退出后，
我们只要看res的值是否为0，为0返回res->next，不为0则返回res即可
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int num = 0;
        ListNode* res = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                num += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                num += s2.top();
                s2.pop();
            }
            res->val = num % 10;
            ListNode* head = new ListNode(num / 10);
            head->next = res;
            res = head;
            num /= 10;
        }
        return res->val == 0 ? res->next : res;
    }
};