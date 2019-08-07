/*
Given a non-empty string s, you may delete at most one character. 
Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True

Explanation: You could delete the character 'c'.

Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

#include <iostream>
#include <string>

using namespace std;


/* 
当遇到不匹配的时候，我们到底是删除左边的字符，还是右边的字符呢，我们的做法是两种情况都要算一遍，只要有一种能返回true，
那么结果就返回true。我们可以写一个子函数来判断字符串中的某一个范围内的子字符串是否为回文串.
*/
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left] != s[right])
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
            ++left;
            --right;
        }
        return true;
    }
    bool isPalindrome(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{
    string s;
    bool result;
    while(cin >> s)
    {
        result = Solution().validPalindrome(s);
        cout << boolalpha << result << endl;
    }
    return 0;
}