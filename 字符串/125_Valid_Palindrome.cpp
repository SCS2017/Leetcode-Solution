/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(!isalnum(s[left])){
                ++left;
            }
            else if(!isalnum(s[right])){
                --right;
            }
            //忽略大小写，大写字母的ASCII值为65~90，小写字母的ASCII值为97~122
            else if((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32){
                return false;
            }
            else{
                ++left;
                --right;
            }
        }
        return true;
    }
};

int main()
{
    string s;
    //输入带有空格的字符串，不能直接用cin >> s，这样只能读取到第一个空格处
    //应该用getline(cin, str)
    while(getline(cin, s)){
        Solution fir;
        bool res = fir.isPalindrome(s);
        cout << boolalpha << res << endl;
    }
    return 0;
}