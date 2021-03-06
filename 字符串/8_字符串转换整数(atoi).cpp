/*
请你来实现一个 atoi 函数，使其能将字符串转换成整数。
首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。
如果数值超过这个范围，qing返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:
输入: "42"
输出: 42

示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
*/

#include <bits/stdc++.h>

using namespace std;

/*
1. 若字符串开头是空格，则跳过所有空格，到第一个非空格字符，如果没有，则返回0.
2. 若第一个非空格字符是符号 +/-，则标记 sign 的真假，
这道题还有个局限性，那就是在 c++ 里面，+-1 和-+1 都是认可的，都是 -1，而在此题里，则会返回0.
3. 若下一个字符不是数字，则返回0. 完全不考虑小数点和自然数的情况，不过这样也好，起码省事了不少。
4. 如果下一个字符是数字，则转为整形存下来，若接下来再有非数字出现，则返回目前的结果。
5. 还需要考虑边界问题，如果超过了整型数的范围，则用边界值替代当前值。
*/
class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0)
            return 0;
        int flag = 1, res = 0, i = 0, n = str.size();
        while(i < n && str[i] == ' ')
            ++i;
        if(i < n && (str[i] == '+' || str[i] == '-'))
            flag = (str[i++] == '+') ? 1 : -1;
        while(i < n && str[i] >= '0' && str[i] <= '9'){
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7))
                return (flag == 1) ? INT_MAX : INT_MIN;
            res = 10 * res + (str[i++] - '0');
        }
        return res * flag;
    }
};

class Solution2 {
public:
    int myAtoi(string str) {
        if(str.size() == 0)
            return 0;
        int flag = 1, i = 0, n = str.size();
        long long res = 0;
        while(i < n && str[i] == ' ')
            ++i;
        if(i >= n)
            return 0;
        if(str[i] == '-'){
            flag = -1;
            ++i;
        }
        if(str[i] == '+'){
            if(flag == -1)
                return 0;
            else
                ++i;
        }
        while(str[i] >= '0' && str[i] <= '9'){
            res = res * 10 + str[i] - '0';
            ++i;
            if(res > INT_MAX)
                break;
        }
        res *= flag;
        if(res > INT_MAX)
            return INT_MAX;
        if(res < INT_MIN)
            return INT_MIN;
        return res;
    }
};

int main(){
    string str;
    while(getline(cin, str)){
        int res = Solution().myAtoi(str);
        cout << res << endl;
    }
    return 0;
}
