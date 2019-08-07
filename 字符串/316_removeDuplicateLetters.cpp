/*
给定一个仅包含小写字母的字符串，去除字符串中重复的字母，使得每个字母只出现一次。需保证返回结果的字典序最小
（要求不能打乱其他字符的相对位置）。

示例 1:
输入: "bcabc"
输出: "abc"

示例 2:
输入: "cbacdcbc"
输出: "acdb"
*/

/*
用堆栈临时保存结果字符串
从栈底到栈顶，对应从左到右
一个字符如果右边还有，可以自由弹出堆栈
一个字符如果右边没有，卡住堆栈，不能弹出
字符入栈前，把堆栈里可弹出的比它大的字符弹出
时间复杂度O(n)
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> num(26, 0);
        vector<bool> in(26, false);
        stack<char> st;
        //num数组记录每个字母出现的次数
        for(int i=0; i<s.length(); ++i){
            ++num[s[i] - 'a'];
        }
        //in数组记录最后结果中的字符，相应位置为true
        for(int i=0; i<s.length(); ++i){
            int c = s[i] - 'a';
            --num[c];
            if(!in[c]){
                while((!st.empty()) && (st.top() > s[i]) && (num[st.top() - 'a'])){
                    in[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(s[i]);
                in[c] = true;
            }
        }
        string answer = "";
        //将堆栈结果弹出，其逆序为结果
        for(; !st.empty(); st.pop()){
            answer = st.top() + answer;
        }
        return answer;
    }
};

/* 
先建立一个哈希表来统计每个字母出现的次数，一个visited数组来纪录每个字母是否被访问过，
我们遍历整个字符串，对于遍历到的字符，先在哈希表中将其值减一，然后看visited中是否被访问过，
若访问过则继续循环，说明该字母已经出现在结果中并且位置已经安排妥当。
如果没访问过，我们和结果中最后一个字母比较，如果该字母的ASCII码小并且结果中的最后一个字母在哈希表中的值不为0
(说明后面还会出现这个字母)，那么我们此时就要在结果中删去最后一个字母且将其标记为未访问，
然后加上当前遍历到的字母，并且将其标记为已访问，以此类推直至遍历完整个字符串s，此时结果里的字符串即为所求。
这里有个小技巧，我们一开始给结果字符串res中放个"0"，就是为了在第一次比较时方便，如果为空就没法和res中的最后一个字符比较了，
而‘0’的ASCII码要小于任意一个字母的，所以不会有问题。最后我们返回结果时再去掉开头那个‘0’即可
*/
class Solution1 {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, visited[256] = {0};
        string res = "0";
        for (auto a : s) ++m[a];
        for (auto a : s) {
            --m[a];
            if (visited[a]) continue;
            while (a < res.back() && m[res.back()]) {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += a;
            visited[a] = 1;
        }
        return res.substr(1);
    }
};

int main()
{
    string s;
    Solution first;
    while(cin >> s)
    {
        string answer;
        answer = first.removeDuplicateLetters(s);
        cout << answer << endl;
    }
    return 0;
}