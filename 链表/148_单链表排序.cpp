/*
单链表排序，要求时间复杂度O(nlogn)，空间复杂度为常数

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5

归并排序  递归
*/

#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void Insert(ListNode *head, int addvalue){
    ListNode* node = new ListNode(addvalue);
    ListNode* p = head;
    if(head == NULL){
        head = node;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = node;
    }
}

void travelList(ListNode* head)
{
    ListNode* node = head;
    if(head == NULL){
        return;
    }
    else{
        cout << node->val << " ";
        while(node->next != NULL){
            node = node->next;
            cout << node->val << " ";
        }
    }
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head, *fast = head, *pre = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    //递归
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val < l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    //非递归
    ListNode* merge1(ListNode* l1, ListNode* l2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* cur = dummyNode;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1)
            cur->next = l1;
        if(l2)
            cur->next = l2;
        return dummyNode->next;
    }
};

ListNode* SortList(ListNode* head)
{
    if(head == 0 || head->next == 0)
    {
        return head;
    }
    //两个结点a和b，a每次走一步，b每次走两步，这样b走到最后，a恰好在中点位置
    ListNode *a = head, *b = head;
    for(; b->next && b->next->next; b = b->next->next, a = a->next)
    ;
    b = SortList(a->next);
    a->next = 0;
    a = SortList(head);
    ListNode *tail = 0;
    while(a && b)
    {
        if(a->val < b->val)
        {
            if(tail)
            {
                tail = tail->next = a;
            }
            else{
                head = tail = a;
            }
            a = a->next;
        }
        else{
            if(tail)
            {
                tail = tail->next = b;
            }
            else{
                head = tail = b;
            }
            b = b->next;
        }
    }
    if(a)
    {
        if(tail)
        {
            tail->next = a;
        }
        else{
            head = a;
        }
    }
    else{
        if(tail)
        {
            tail->next = b;
        }
        else{
            head = b;
        }
    }
    return head; 
}

int main()
{
    int n;
    while(cin >> n)
    {
        n--;
        int value;
        cin >> value;
        ListNode root(value);
        while(n--)
        {
            int newValue;
            cin >> newValue;
            Insert(&root, newValue);
        }
        travelList(&root);
        cout << endl;
        ListNode* res;
        res = SortList(&root);
        travelList(res);
        cout << endl;
    }
    return 0;
}