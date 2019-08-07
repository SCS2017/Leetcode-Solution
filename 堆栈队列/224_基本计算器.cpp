/*
现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:
输入: "1 + 1"
输出: 2

示例 2:
输入: " 2-1 + 2 "
输出: 3

示例 3:
输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23

说明：
你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。
*/

#include <bits/stdc++.h>

using namespace std;

/*
题目限制了表达式中只有加减号，数字，括号和空格，没有乘除，那么就没啥计算的优先级之分了。于是这道题就变的没有那么复杂了。
我们需要一个栈来辅助计算，用个变量sign来表示当前的符号，我们遍历给定的字符串s，如果遇到了数字，由于可能是个多位数，
所以我们要用while循环把之后的数字都读进来，然后用sign*num来更新结果res；
如果遇到了加号，则sign赋为1，如果遇到了符号，则赋为-1；
如果遇到了左括号，则把当前结果res和符号sign压入栈，res重置为0，sign重置为1；
如果遇到了右括号，结果res乘以栈顶的符号，栈顶元素出栈，结果res加上栈顶的数字，栈顶元素出栈。
*/
class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1, n = s.size();
        stack<int> mystack;
        for(int i = 0; i < n; ++i){
            if(s[i] >= '0'){
                int num = 0;
                while(i < n && s[i] >= '0')
                    num = num * 10 + (s[i++] - '0');
                res += sign * num;
                --i;
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '('){
                mystack.push(res);
                mystack.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                res *= mystack.top();
                mystack.pop();
                res += mystack.top();
                mystack.pop();
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}
