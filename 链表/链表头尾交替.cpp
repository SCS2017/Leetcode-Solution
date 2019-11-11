/* 
给个链表1->2->3->4->5->6 把它变成1->6->2->5->3->4
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x) {}
};

ListNode* createList(int arr[], int n){
    if(n == 0)
        return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for(int i = 1; i < n; ++i){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout << cur->val << " -> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

ListNode* reverse(ListNode* head){
    ListNode* pre = NULL, *cur = head;
    while(cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void reorder(ListNode* head){
    if(head == NULL || head->next == NULL)
        return;
    // 找出中间结点
    ListNode* fast = head, *slow = head;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* head1 = slow->next;
    slow->next = NULL;
    // 反转后一半链表
    ListNode* newHead1 = reverse(head1);
    // 合并链表
    while (head && newHead1){
        ListNode* next = head->next;
        ListNode* next1 = newHead1->next;
        head->next = newHead1;
        head = next;
        newHead1->next = head;
        newHead1 = next1;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    ListNode* head = createList(arr, 6);
    printList(head);
    reorder(head);
    printList(head);
    return 0;
}
