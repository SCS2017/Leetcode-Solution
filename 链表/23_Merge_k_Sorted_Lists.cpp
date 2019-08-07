/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        int n = lists.size();
        while(n > 1){
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; ++i){
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
};


/*使用优先队列
要对k个链表进行合并排序，可以维护一个最小堆。步骤如下：
首先将每个非空链表的表头加入最小堆；
每次弹出一个堆顶元素作为链表的下一个节点，如果此时堆顶元素的下一个节点非空，将它加入最小堆；
重复步骤2，直到最小堆为空。

注意：最小堆的元素类型是链表节点指针ListNode*不是ListNode。

假设所有链表的节点总数为n
时间复杂度O(n log k)空间复杂度O(k)

*/
class Solution1 {
public:
    static bool cmp(ListNode* l1, ListNode* l2){
        //小的优先级高
        return l1->val > l2->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //最小优先队列
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)*> que(cmp);
        for(auto node: lists){
            if(node)
                que.push(node);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(!que.empty()){
            auto tmp = que.top();
            que.pop();
            if(tmp->next) 
                que.push(tmp->next);
            cur->next = tmp;
            cur = cur->next;
        }
        return dummy->next;
    }
};


int main()
{
    return 0;
}