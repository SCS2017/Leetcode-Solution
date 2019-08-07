#include <bits/stdc++.h>

using namespace std;

/*
题目：
一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈，
除此之外可以申请新的变量，但不能申请额外的数据结构。如何完成排序？

题解：
需要用到辅助栈。stack执行pop操作，弹出元素记为cur；
如果cur小于或等于assist的栈顶元素，则将cur直接压入assist；
如果cur大于assist的栈顶元素，则将assist的元素逐一弹出并压入stack，知道cur小于或等于assist的栈顶元素，再将cur压入assist
执行上述操作后，直到stack空，将assist所有元素逐一压入stack
*/

void sortStack(stack<int>& s){
    stack<int> tmp;
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        //cur < tmp.top()栈弹出的元素为从小到大，cur > tmp.top()栈弹出的元素为从大到小 
        while(!tmp.empty() && cur < tmp.top()){
            s.push(tmp.top());
            tmp.pop();
        }
        tmp.push(cur);
    }
    while(!tmp.empty()){
        s.push(tmp.top());
        tmp.pop();
    }
}

int main()
{
    vector<int> arr{3, 4, 2, 1, 5};
    stack<int> s;
    for (int i = 0; i < arr.size(); ++i) {
        s.push(arr[i]);
    }
    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}