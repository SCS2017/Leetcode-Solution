/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* 
记忆化搜索
记忆数组 memo[i] 定义为范围为 [i, n] 的子字符串是否可以拆分，初始化为 -1，表示没有计算过，如果可以拆分，则赋值为1，反之为0。
在之前讲 brute force 解法时，博主提到的是讲分成两段的后半段的调用递归函数，我们也可以不取出子字符串，而是用一个 start 变量，
来标记分段的位置，这样递归函数中只需要从 start 的位置往后遍历即可，在递归函数更新记忆数组 memo 即可
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check(s, 0, memo, wordSet);
    }
    bool check(string s, int start, vector<int>& memo, unordered_set<string>& wordSet){
        if(start >= s.size())
            return true;
        if(memo[start] != -1)
            return memo[start];
        for(int i = start + 1; i <= s.size(); ++i){
            if(wordSet.count(s.substr(start, i-start)) && check(s, i, memo, wordSet)){
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};


/*
DP解法的两大难点，定义dp数组跟找出状态转移方程，先来看dp数组的定义，这里我们就用一个一维的dp数组，
其中dp[i]表示范围[0, i)内的子串是否可以拆分，注意这里dp数组的长度比s串的长度大1，是因为我们要处理空串的情况，
我们初始化dp[0]为true，然后开始遍历。注意这里我们需要两个for循环来遍历，因为此时已经没有递归函数了，
所以我们必须要遍历所有的子串，我们用j把[0, i)范围内的子串分为了两部分，[0, j) 和 [j, i)，其中范围 [0, j) 就是dp[j]，
范围 [j, i) 就是s.substr(j, i-j)，其中dp[j]是之前的状态，我们已经算出来了，可以直接取，
只需要在字典中查找s.substr(j, i-j)是否存在了，如果二者均为true，将dp[i]赋为true，并且break掉，
此时就不需要再用j去分[0, i)范围了，因为[0, i)范围已经可以拆分了。
最终我们返回dp数组的最后一个值，就是整个数组是否可以拆分的布尔值了，代码如下：
*/
class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i = 1; i < dp.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j] && wordSet.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        for(auto flag: dp)
            cout << flag << " ";
        return dp.back();
    }
};

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    string s1 = "applepenapple";
    vector<string> wordDict1 = {"apple", "pen"};
    bool res;
    Solution1 fir;
    res = fir.wordBreak(s1, wordDict1);
    cout << boolalpha << res << endl;
    return 0;
}