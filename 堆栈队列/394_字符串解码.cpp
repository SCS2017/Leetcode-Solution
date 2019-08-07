/*
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:
s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

*/

#include <bits/stdc++.h>

using namespace std;

/*
我们用两个 stack，一个用来保存个数，一个用来保存字符串，我们遍历输入字符串，如果遇到数字，我们更新计数变量 cnt；
如果遇到左括号，我们把当前 cnt 压入数字栈中，把当前t压入字符串栈中；
如果遇到右括号时，我们取出数字栈中顶元素，存入变量k，然后给字符串栈的顶元素循环加上k个t字符串，
然后取出顶元素存入字符串t中；如果遇到字母，我们直接加入字符串t中即可。
*/
class Solution {
public:
    string decodeString(string s) {
        stack<int> stack_num;
        stack<string> stack_str;
        string res = "", tmp = "";
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9')
                cnt = cnt * 10 + s[i] - '0';
            else if(s[i] == '['){
                stack_num.push(cnt);
                stack_str.push(tmp);
                cnt = 0;
                tmp.clear();
            }
            else if(s[i] == ']'){
                int k = stack_num.top();
                stack_num.pop();
                for(int j = 0; j < k; ++j)
                    stack_str.top() += tmp;
                tmp = stack_str.top();
                stack_str.pop();
            }
            else
                tmp += s[i];
        }
        res = res + tmp;
        return res;
    }
};

int main(){
    string s;
    while(cin >> s){
        string res = Solution().decodeString(s);
        cout << res << endl;
    }
    return 0;
}
