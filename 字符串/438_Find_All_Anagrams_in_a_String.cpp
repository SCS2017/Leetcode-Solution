/*
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：
字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。

示例 1:
输入:
s: "cbaebabacd" p: "abc"
输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

示例 2:
输入:
s: "abab" p: "ab"
输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
*/
#include <iostream>
#include <vector>

using namespace std;

/*
两个哈希表，分别记录p的字符个数，和s中前p字符串长度的字符个数，然后比较，如果两者相同，则将0加入结果res中，
然后开始遍历s中剩余的字符，每次右边加入一个新的字符，然后去掉左边的一个旧的字符，每次再比较两个哈希表是否相同即可
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //如果s为空或者s的长度小于p，则返回空值
        if(s.empty() || s.length() < p.length()){
            return {};
        }
        vector<int> res, m1(256, 0), m2(256, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++m1[s[i]]; ++m2[p[i]];
        }
        if (m1 == m2) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++m1[s[i]]; 
            --m1[s[i - p.size()]];
            if (m1 == m2) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};

/*利用滑动窗口Sliding Window的方法
首先统计字符串p的字符个数，然后用两个变量left和right表示滑动窗口的左右边界，用变量cnt表示字符串p中需要匹配的字符个数，
然后开始循环，如果右边界的字符已经在哈希表中了，说明该字符在p中有出现，则cnt自减1，然后哈希表中该字符个数自减1，
右边界自加1，如果此时cnt减为0了，说明p中的字符都匹配上了，那么将此时左边界加入结果res中。
如果此时right和left的差为p的长度，说明此时应该去掉最左边的一个字符，我们看如果该字符在哈希表中的个数大于等于0，
说明该字符是p中的字符，为啥呢，因为上面我们有让每个字符自减1，如果不是p中的字符，那么在哈希表中个数应该为0，
自减1后就为-1，所以这样就知道该字符是否属于p，如果我们去掉了属于p的一个字符，cnt自增1
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.empty()){
            return {};
        }
        vector<int> res, freq(256, 0);
        int l = 0, r = 0, cnt = p.length();
        for(char c: p){
            ++freq[c];
        }
        while(r < s.length()){
            if(freq[s[r++]]-- >= 1){
                --cnt;
            }
            if(cnt == 0){
                res.push_back(l);
            }
            if(r - l == p.length() && freq[s[l++]]++ >= 0){
                ++cnt;
            }
        }
        return res;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    Solution fir;
    vector<int> res = fir.findAnagrams(s, p);
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}