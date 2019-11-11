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

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        quickSortList(head, NULL);
        return head;
    }
    void quickSortList(ListNode* head, ListNode* tail){
        if(head == tail || head->next == tail)
            return;
        int pivot = head->val;
        ListNode* left = head, *cur = head->next;
        while(cur && cur != tail){
            if(cur->val < pivot){
                left = left->next;
                swap(left, cur);
            }
            cur = cur->next;
        }
        swap(head, left);
        quickSortList(head, left);
        quickSortList(left->next, tail);
    }
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		quickSort(head, nullptr);
		return head;
	}

	void quickSort(ListNode* head, ListNode* tail) {
		if (head == tail || head->next == nullptr) {
			return;
		}

		ListNode* mid = partition(head, tail);

		quickSort(head, mid);
		quickSort(mid->next, tail);
	}

	ListNode* partition(ListNode* head, ListNode * tail) {
		int pivot = head->val;
		ListNode* s = head;
		ListNode* cur = head->next;
		while (cur != nullptr && cur != tail)
		{
			if (cur->val < pivot) {
				s = s->next;
				swap(s, cur);
			}
			cur = cur->next;
		}
		swap(s, head);
		return s;
	}

	void swap(ListNode* a, ListNode* b) {
		int temp = a->val;
		a->val = b->val;
		b->val = temp;
	}
};


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
        res = Solution().sortList(&root);
        travelList(res);
        cout << endl;
    }
    return 0;
}