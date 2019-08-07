/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 

Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
分析：
暴力枚举？起点、终点、判断重复
优化——双指针、滑动窗口
动态维护窗口[i,j]的字符情况
如何维护？保证窗口(i,j)之间没有重复字符
如果没有重复字符，j向右滑动，直到j被“卡住”
向右滑动指针i直到j“解围”，滑动过程中j-i减小，所以不会错过最优解
时间复杂度O(n)

字符占1个字节，8位二进制位
signed char类型的范围是-128~127，而unsigned char的范围是0~255。
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int answer = 0;
    vector<bool> have(256, false);
    for(int i = 0, j = 0; ; ++i)
    {
        while((j < s.length()) && (!have[s[j]]))
        {
            have[s[j++]] = true;
        }
        answer = max(answer, j - i);
        //如果到达字符串尾，说明整个字符串不包含重复字符，直接结束循环
        if(j >= s.length())
        {
            break;
        }
        while(s[i] != s[j])
        {
            have[s[i++]] = false;
        }
        have[s[i]] = false;
    }
    return answer;
}

/*
立一个HashMap，建立每个字符和其最后出现位置之间的映射，然后我们需要定义两个变量res和left，其中res用来记录最长无重复子串的
长度，left指向该无重复子串左边的起始位置的前一个，由于是前一个，所以初始化就是-1，然后我们遍历整个字符串，
对于每一个遍历到的字符，如果该字符已经在HashMap中存在了，并且如果其映射值大于left的话，那么更新left为当前映射值。
然后映射值更新为当前坐标i，这样保证了left始终为当前边界的前一个位置，然后计算窗口长度的时候，直接用i-left即可，
用来更新结果res
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1;
        unordered_map<int, int> m;
        for(int i = 0; i < s.length(); ++i){
            if(m.count(s[i]) && m[s[i]] > left)
                left = m[s[i]];
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;
        int res = 0;
        while(l < s.length()){
            if(r + 1 < s.length()  && freq[s[r + 1]] == 0){
                freq[s[++r]]++;
            }
            else{
                freq[s[l++]]--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main()
{
    string str;
    while(cin >> str){
        int answer = Solution1().lengthOfLongestSubstring(str);
        cout << answer << endl;
    }
    return 0;
}