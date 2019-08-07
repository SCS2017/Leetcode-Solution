/**
Leetcode 328  Odd Even Linked List
将链表中的所有的偶数位置元素放到所有的奇数位置元素后面
O(1) space complexity and O(nodes) time complexity

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
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

//用两个链表代表原链表中奇数位置结点和偶数位置结点，然后连上就可以了
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *head1 = 0, *tail1 = 0, *head2 = 0, *tail2 = 0;
        for(int i = 1; head; ++i, head = head->next){
            if(i & 1){
                if(tail1){
                    tail1 = tail1->next = head;
                }
                else{
                    tail1 = head1 = head;
                }
            }
            else{
                if(tail2){
                    tail2 = tail2->next = head;
                }
                else{
                    head2 = tail2 = head;
                }
            }
        }
        if(tail1){
            tail1->next = head2;
        }
        else{
            head1 = head2;
        }
        if(tail2){
            tail2->next = 0;
        }
        return head1;
    }
};

class Solution1 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* odd = head, *even = head->next, *even_head = even;
        while(even && even->next){
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = even_head;
        return head;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = createLinkedList(arr, n);
    printListNode(head);
    ListNode* head2 = Solution().oddEvenList(head);
    printListNode(head2);
    return 0;
}