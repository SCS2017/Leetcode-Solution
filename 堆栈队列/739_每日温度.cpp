/*
根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。
如果之后都不会升高，请输入 0 来代替。
例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。
*/
#include <bits/stdc++.h>

using namespace std;

// 暴力解法，无法通过
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        for(int i = 0; i < T.size(); ++i){
            int j = i+1;
            for(; j < T.size(); ++j){
                if(T[j] > T[i])
                    break;
            }
            if(j == T.size())
                res.push_back(0);
            else
                res.push_back(j-i);
        }
        return res;
    }
};

/*
使用递减栈Descending Stack来做，栈里只有递减元素，思路是这样的，我们遍历数组，如果栈不空，且当前数字大于栈顶元素，
那么如果直接入栈的话就不是递减栈了，所以我们取出栈顶元素，那么由于当前数字大于栈顶元素的数字，而且一定是第一个大于栈顶元素的数，
那么我们直接求出下标差就是二者的距离了，然后继续看新的栈顶元素，直到当前数字小于等于栈顶元素停止，
然后将数字入栈，这样就可以一直保持递减栈，且每个数字和第一个大于它的数的距离也可以算出来了
*/
class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> s;
        for(int i = 0; i < n; ++i){
            while(!s.empty() && T[i] > T[s.top()]){
                auto t = s.top();
                s.pop();
                res[t] = i - t;
            }
            s.push(i);
        }
        return res;
    }
};

int main(){
    
    return 0;
}
