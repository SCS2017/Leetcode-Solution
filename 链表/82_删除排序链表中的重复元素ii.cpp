/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:
输入: 1->1->1->2->3
输出: 2->3
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

/*设置虚拟头结点
定义一个前驱指针和一个现指针，每当前驱指针指向新建的节点，现指针从下一个位置开始往下遍历，遇到相同的则继续往下，
直到遇到不同项时，把前驱指针的next指向下面那个不同的元素。如果现指针遍历的第一个元素就不相同，则把前驱指针向下移一位。
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* pre = dummyNode;
        while(pre->next){
            ListNode* cur = pre->next;
            //如果满足条件，cur目前指向的就是某个重复元素最后出现的位置
            while(cur->next && cur->val == cur->next->val)
                cur = cur->next;
            //如果两者不相等，就将pre->next指向cur>next
            if(cur != pre->next)
                pre->next = cur->next;
            else
                pre = pre->next;
        }
        return dummyNode->next;
    }
};

class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *head1 = 0, *tail1 = 0;
        while(head){
            ListNode *tmp;
            bool dup = false;
            for(tmp = head->next; (tmp) && (tmp->val == head->val); tmp = tmp->next){
                //if(tmp) cout << tmp->val << endl;
                dup = true;
            }
            if(!dup){
                if(tail1){
                    tail1 = tail1->next = head;
                }
                else{
                    head1 = tail1 = head;
                }
            }
            head = tmp;
        }
        if(tail1){
            tail1->next = 0;
        }
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
        cout << endl;
    }
    return 0;
}