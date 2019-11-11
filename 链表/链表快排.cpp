#include <bits/stdc++.h>
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

// 不能使用头尾指针，对换元素位置
// 可以使用两个指针p和q，这两个指针均往next方向移动，移动的过程中保持p之前的key都小于选定的key，
// p和q之间的key都大于选定的key，那么当q走到末尾的时候便完成了一次支点的寻找
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        if(!head || !head->next)
            return head;
        ListNode* tail = head;
        while(tail)
            tail = tail->next;
        quickSort(head, tail);
        return head;
    }
    void quickSort(ListNode* head, ListNode* tail){
        if(head != tail){
            ListNode* p = partition(head, tail);
            quickSort(head, p);
            if(p->next)
                quickSort(p->next, tail);
        }
    }
    ListNode* partition(ListNode* begin, ListNode* end){
        int pivot = begin->val;
        ListNode* p = begin, *q = p->next;
        while(q != end){
            if(q->val < pivot){
                p = p->next;
                swap(p->val, q->val);
            }
            q = q->next;
        }
        swap(p->val, begin->val);
        return p;
    }
};

int main(){
    int arr[] = {1, 2, 7, 5, 6, 0};
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = createLinkedList(arr, n);
    printListNode(head);
    ListNode* head1 = Solution().sortList(head);
    printListNode(head1);
    return 0;
}

