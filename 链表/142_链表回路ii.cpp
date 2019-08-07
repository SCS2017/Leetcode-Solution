/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
说明：不允许修改给定的链表。

进阶：
你是否可以不用额外空间解决此题？
*/

#include <iostream>
#include <unordered_set>

using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        for(ListNode* t = head; t; t = t->next)
        {
            if(s.find(t) != s.end())
            {
                return t;
            }
            s.insert(t);
        }
        return 0;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *x = head, *y = head;
        do{
            if(x == 0){
                return 0;
            }
            x = x->next;
            if(y == 0){
                return 0;
            }
            y = y->next;
            if(y == 0){
                return 0;
            }
            y = y->next;
            if(y == 0){
                return 0;
            }
        }while(x != y);
        for(x = head; x!=y; x = x->next, y = y->next)
        ;
        return x;
    }
};

int main()
{
    return 0;
}