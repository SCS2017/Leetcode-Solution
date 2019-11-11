/* 
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

示例 2:
输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.size(); ++i){
            dp[i] = (s[i-1] == '0' ? 0 : dp[i-1]);
            if(i > 1 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))
                dp[i] += dp[i-2];
        }
        return dp.back();
    }
};

int main(){
    
    return 0;
}
