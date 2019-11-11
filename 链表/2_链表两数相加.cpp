/*
给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL) {
            return l1 == NULL ? l2 : l1;
        }
        int value = l1->val + l2->val;
        ListNode* result = new ListNode(value % 10);  //对10取余即为该位置上的数
        result->next = addTwoNumbers(l1->next, l2->next);
        if (value >= 10)   //如果两数之和大于10，在下一位置加上对10取整的结果
            result->next = addTwoNumbers(new ListNode(value / 10), result->next);
        return result;

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
    res = first.addTwoNumbers(&root1, &root2);
    travelList(res);
    cout << endl;
    return 0;
}