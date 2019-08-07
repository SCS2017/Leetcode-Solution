/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
*/

#include <iostream>

using namespace std;
 
struct ListNode{
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

/*
遍历这个链表，每个结点和其后面的结点比较，如果结点值相同了，我们只要将前面结点的next指针跳过紧挨着的相同值的结点，
指向后面一个结点。
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next){
            if(cur->val == cur->next->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};

class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* head1 = 0, *tail1 = 0;
        for(; head; head = head->next){
            if(tail1 == 0 || tail1->val != head->val){
                if(tail1)
                    tail1 = tail1->next = head;
                else
                    head1 = tail1 = head;
            }
        }
        if(tail1)
            tail1->next = 0;
        return head1;
    }
};

int main()
{
    int n;
    Solution first;
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
        res = first.deleteDuplicates(&root);
        travelList(res);
    }
    return 0;
}