'''
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
解答
开辟一个栈sta，遍历字符串，对于遍历的每一个字符s，处理情况如下：
如果s是+,-,*,/中的一个，则弹出栈的两个元素num1和num2，根据运算符计算局部结果res，例如如果运算符为*，
则res = num1 * num2。然后将res压入栈；否则，s代表的是数字，将s转换成数字压入栈中。
遍历结束后，sta栈顶元素即为所求。

时间复杂度：O(n) 空间复杂度：O(n)
'''
class Solution:
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for ch in tokens:
            if ch in ['+', '-', '*', '/']:
                num1 = stack[-1]
                stack.pop()
                num2 = stack[-1]
                stack.pop()
                if ch == '+':
                    res = num2 + num1
                elif ch == '-':
                    res = num2 - num1
                elif ch == '*':
                    res = num2 * num1
                else:
                    res = int(num2 / num1)
                stack.append(res)
            else:
                stack.append(int(ch))
        return stack[-1]

sol = Solution()
tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
print(sol.evalRPN(tokens))