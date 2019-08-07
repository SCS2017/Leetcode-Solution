/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/

#include <bits/stdc++.h>

using namespace std;

//从中间往两边扩展，寻找最长的回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 2)
            return s;
        int start = 0, maxLen = 0;
        for(int i = 0; i < s.length()-1; ++i){
            help(s, i, i, start, maxLen);
            help(s, i, i+1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }
    void help(string s, int left, int right, int& start, int& maxLen){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            ++right;
            --left;
        }
        if(maxLen < right - left - 1){
            start = left+1;
            maxLen = right-left-1;
        }
    }
};

int main(){
    
    return 0;
}

/*Python暴力求解
class Solution:
    def isPalindrome(self, s):
        return s[::-1] == s
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2:
            return s;
        maxLen = 0
        res = ""
        for i in range(len(s)):
            for j in range(i+1, len(s)+1):
                if self.isPalindrome(s[i:j]):
                    if maxLen < j - i:
                        maxLen = j-i
                        res = s[i:j]
        return res
*/