/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

#include <iostream>
#include <vector>

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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        while(p->next && p->next->next){
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            
            p = node1;
        }
        ListNode* resNode = dummyHead->next;
        delete dummyHead;
        
        return resNode;
    }
};

int main()
{
    // int arr[] = {1, 2, 3, 4, 5};
    // int n = sizeof(arr) / sizeof(int);
    // ListNode* head = createLinkedList(arr, n);
    // printListNode(head);
    // ListNode* head2 = Solution().swapPairs(head);
    // printListNode(head2);
    vector<int> nums1, nums2;
    int num1, num2;
    //从键盘输入两行数据，每行数据构建一个链表
    while(cin >> num1){
        nums1.push_back(num1);
        if(cin.get() == '\n'){
            break;
        }
    }
    while(cin >> num2){
        nums2.push_back(num2);
        if(cin.get() == '\n'){
            break;
        }
    }
    for(int i = 0; i < nums1.size(); ++i){
        cout << nums1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < nums2.size(); ++i){
        cout << nums2[i] << " ";
    }
    cout << endl;
    return 0;
}