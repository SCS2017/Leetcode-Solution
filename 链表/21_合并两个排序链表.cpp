/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    //递归
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { 
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    // //非递归
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) { 
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
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
        cur->next = l1 ? l1 : l2;
        return head->next; 
    }
};

int main()
{
    int m, n;
    //输入第一个链表
    cin >> n;
    n--;
    int value1;
    cin >> value1;
    ListNode root1(value1);
    while(n--)
    {
        int newValue1;
        cin >> newValue1;
        Insert(&root1, newValue1);
    }
    //输入第二个链表
    cin >> m;
    m--;
    int value2;
    cin >> value2;
    ListNode root2(value2);
    while(m--)
    {
        int newValue2;
        cin >> newValue2;
        Insert(&root2, newValue2);
    }
    travelList(&root1);
    cout << endl;
    travelList(&root2);
    cout << endl;
    ListNode* res;
    Solution first;
    res = first.mergeTwoLists(&root1, &root2);
    travelList(res);
    cout << endl;
    return 0;
}