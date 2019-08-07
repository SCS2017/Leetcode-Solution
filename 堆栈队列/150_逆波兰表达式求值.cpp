/*
根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9

示例 2：
输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6

示例 3：
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

/*
解答
开辟一个栈sta，遍历字符串，对于遍历的每一个字符s，处理情况如下：
如果s是+,-,*,/中的一个，则弹出栈的两个元素num1和num2，根据运算符计算局部结果res，例如如果运算符为*，
则res = num1 * num2。然后将res压入栈；否则，s代表的是数字，将s转换成数字压入栈中。
遍历结束后，sta栈顶元素即为所求。

时间复杂度：O(n) 空间复杂度：O(n)
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> s;
        for(auto token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(token == "+")
                    res = num2 + num1;
                else if(token == "-")
                    res = num2 - num1;
                else if(token == "*")
                    res = num2 * num1;
                else if(token == "/")
                    res = num2 / num1;
                s.push(res);
            }
            else
                s.push(toInt(token));
        }
        return s.top();
    }
    int toInt(string s){
        int res = 0;
        if(s[0] != '-'){
            for(int i = 0; i < s.size(); ++i)
                res = res * 10 + s[i] - '0';
            return res;
        }
        else
            return -1 * toInt(s.substr(1));
    }
};