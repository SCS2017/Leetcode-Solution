/* 
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。
返回所有这些可能的句子。

说明：
分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

示例 1：
输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]

示例 2：
输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。

示例 3：
输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/* 
如果s为空了，题目中说了给定的s不会为空，但是我们递归函数处理时s是会变空的，这时候我们是直接返回空集吗，这里有个小trick，
我们放一个空字符串返回，为啥要这么做呢？观察题目中的Output，发现单词之间是有空格，而最后一个单词后面没有空格，
所以这个空字符串就起到了标记当前单词是最后一个，那么我们就不要再加空格了。
遍历wordDict数组，如果某个单词是s字符串中的开头单词的话，对后面部分调用递归函数，将结果保存到rem中，然后遍历里面的所有字符串，
和当前的单词拼接起来，这里就用到了我们前面说的trick
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string> > m;
        return helper(s, wordDict, m);
    }
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string> >& m){
        if(m.count(s))
            return m[s];
        if(s.empty())
            return {""};
        vector<string> res;
        for(string word: wordDict){
            if(s.substr(0, word.size()) != word)
                continue;
            vector<string> rem = helper(s.substr(word.size()), wordDict, m);
            for(string str: rem){
                res.push_back(word + (str.empty() ? "": " ") + str);
            }
        }
        return m[s] = res;
    }    
};

class Solution1 {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = wordBreak(s.substr(word.size()), wordDict);
            for (string str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s] = res;
    }
};

int main(){
    
    return 0;
}
