/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

#include <iostream>
#include <stack>

using namespace std;

//使用栈

class Solution {
public:
	bool isValid(string s) {
		stack<char> mystack;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				mystack.push(s[i]);
			} else {
				if (mystack.empty())
					return false;
				if (mystack.top() == '(' && s[i] == ')')
					mystack.pop();
				else if (mystack.top() == '[' && s[i] == ']')
					mystack.pop();
				else if (mystack.top() == '{' && s[i] == '}') 
					mystack.pop();
				else
					return false;
			}
		}
		return mystack.empty();
	}
};
