/*
编写一个程序，找到两个单链表相交的起始节点。

例如，下面的两个链表：
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
在节点 c1 开始相交。

注意：
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

/*
如果两个链长度相同的话，那么对应的一个个比下去就能找到，所以只需要把长链表变短即可。
具体算法为：分别遍历两个链表，得到分别对应的长度。
然后求长度的差值，把较长的那个链表向后移动这个差值的个数，然后一一比较即可。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA = lengthOfList(headA);
        int lenB = lengthOfList(headB);
        if(lenA < lenB){
            for(int i = 0; i < lenB - lenA; ++i){
                headB = headB->next;
            }
        }
        else{
            for(int i = 0; i < lenA - lenB; ++i){
                headA = headA->next;
            }
        }
        while(headA && headB && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return (headA && headB) ? headA : NULL;
    }
private:
    int lengthOfList(ListNode* head){
        int cnt = 0;
        while(head){
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
};