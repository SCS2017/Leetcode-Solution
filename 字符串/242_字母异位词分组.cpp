/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"],

输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：
所有输入均为小写字母。
不考虑答案输出的顺序。
*/

#include <bits/stdc++.h>
using namespace std;

/*
将每个字符串排序，使用哈希表记录排序后的字符串相同的字符串
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty())
            return res;
        unordered_map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); ++i){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        for(auto it: m){
            res.push_back(it.second);
        }
        return res;
    }
};

int main(){
    
    return 0;
}
