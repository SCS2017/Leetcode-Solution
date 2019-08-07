/*
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:
输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".

示例 2:
输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".

注意:
输入的字符串长度不会超过1000。
*/

#include <bits/stdc++.h>

using namespace std;

//暴力解法
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty())
            return 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            for(int j = i; j < s.size(); ++j){
                if(IsPalindrome(s.substr(i, j-i+1)))
                    ++cnt;
            }
        }
        return cnt;
    }
    bool IsPalindrome(string s){
        if(s.size() < 2)
            return true;
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};

/*
以字符串中的每一个字符都当作回文串中间的位置，然后向两边扩散，每当成功匹配两个左右两个字符，结果res自增1，然后再比较下一对。
注意回文字符串有奇数和偶数两种形式，如果是奇数长度，那么i位置就是中间那个字符的位置，所以我们左右两遍都从i开始遍历；
如果是偶数长度的，那么i是最中间两个字符的左边那个，右边那个就是i+1，这样就能cover所有的情况啦，而且都是不同的回文子字符串。
*/
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty())
            return 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            count(s, i, i, cnt);
            count(s, i, i+1, cnt);
        }
        return cnt;
    }
    void count(string s, int i, int j, int& cnt){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            --i;
            ++j;
            ++cnt;
        }
    }
};
