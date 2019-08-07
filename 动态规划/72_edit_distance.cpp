/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 
to word2.
You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

/*
换个角度考虑问题，变为字符串“对齐问题”
S = "ABCF"  T = "DBFG"
S   A   B   C   F   -  
T   D   B   -   F   G
对应位置相同不扣分，不同则扣一分（修改）
两个特殊字符“-”不会对应
S位置“-”代表增加字符
T位置“-”代表删掉字符
使扣分最少
*/

/*动态规划
dp[i][j]表示S的前i个位置和T的前就个位置对齐的最小得分
dp[i][j] = min(dp[i-1][j-1] + same(i, j), dp[i-1][j] + 1, dp[i][j-1] + 1)
其中 
    dp[i-1][j-1] + same(i, j)对应S第i个字符和T第j个字符对齐
    dp[i-1][j] + 1对应S第i个字符和-对齐，即删掉S中第i个字符
    dp[i][j-1] + 1对应T第j个字符和-对齐，即在S中加入该字符
初值
    dp[0][j] = j, dp[i][0] = i (i≥0， j≥0)
时空复杂度O(length(S) * length(T))
空间优化————省掉一维
    对每个i，正向循环j
    注意保存dp[i-1][j-1]，因为j-1已经是“新值”
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if(i == 0){
                    dp[i][j] = j;
                }
                else if(j == 0){
                    dp[i][j] = i;
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 1), 
                                   min(dp[i-1][j], dp[i][j-1]) + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    return 0;
}