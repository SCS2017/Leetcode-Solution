/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//使用数组创建链表
ListNode* createLinkedList(int arr[], int n){
    if(n == 0){
        return NULL;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i = 1; i < n; ++i){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    return head;
}

//打印链表
void printListNode(ListNode* head){
    ListNode* curNode = head;
    while(curNode){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }
    cout << "NULL" << endl;
    return;
}

//释放内存
void deleteLinkedList(ListNode* head){
    ListNode* curNode = head;
    while(curNode){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* p = head;
        head = reverseList(p->next);
        p->next->next = p;
        p->next = NULL;
        return head;
    }
};
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = createLinkedList(arr, n);
    printListNode(head);
    ListNode* head2 = Solution().reverseList(head);
    printListNode(head2);
    deleteLinkedList(head2);
    return 0;
}
