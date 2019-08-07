/* 
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"

示例 2:
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
*/

#include <bits/stdc++.h>
using namespace std;


//题目要求的是求连续的最长有效括号，即连续的子串，开始理解错了，以为是不连续的，用栈做的，直接求所有合法的括号
//使用stack保存每个字符的位置i，遍历求有效括号的长度即可
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(')
                st.push(i);
            else{
                if(st.empty()){
                    start = i + 1;
                }
                else{
                    st.pop();
                    res = st.empty() ? max(res, i-start+1) : max(res, i-st.top());
                }
            }
        }
        return res;
    }
};

// 动态规划
/* 
我们定义一个dp数组，其中第 i 个元素表示以下标为 i 的字符结尾的最长有效子字符串的长度。初始化为 0 。
我们每两个字符检查一次，如果满足如下条件
1.s[i] = ')' 且 s[i−1]='(' ，也就是字符串形如"……()"，我们可以推出：
dp[i] = dp[i-2] + 2

2.s[i] = ')' 且 s[i−1] = ')'，也就是字符串形如 ".......))"，我们可以推出：
如果 s[i - dp[i - 1] - 1] = '('，那么
dp[i] = dp[i−1] + dp[i−dp[i−1]−2] + 2
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, start = 0;
        vector<int> dp(s.size()+1, 0);
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == ')'){
                if(s[i-1] == '(')
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                else if(i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(')
                    dp[i] = dp[i-1] + ((i - dp[i-1]) >= 2 ? dp[i-dp[i-1]-2] : 0) + 2;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main(){
    
    return 0;
}
