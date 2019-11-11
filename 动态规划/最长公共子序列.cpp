/*
给定两个字符串S1和S2，求两个字符串的最长公共子序列的长度

例如
S1 = 'ABCD'
S2 = 'AEBD'
则结果为 'ABD'
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
LCS(m ,n)表示S1[0...m]和S2[0...n]的最长公共子序列的长度
S1[m-1] == S2[n-1]:
    LCS(m, n) = 1 + LCS(m - 1, n - 1)
S1[m-1] != S2[n-1]:
    LCS(m, n) = max(LCS(m - 1, n), LCS(m, n - 1))
*/
class Solution{
public:
    int lengthOflongestCommonSequence(string& str1, string& str2){
        int m = str1.length(), n = str2.length();
        if(m == 0 || n == 0)
            return 0;
        dp = vector<vector<int> >(m+1, vector<int>(n+1, 0));
        for(int i = 1; i < m+1; ++i){
            for(int j = 1; j < n+1; ++j){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    //该函数找出所有的LCS的序列，并将其存在vector中
    //注意这里形参lcs_str不可以为引用，这里需要每次调用lcs_str都重新生成一个对象
    void PrintAllLCS(string& str1, string& str2, int i, int j, string lcs_str){
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                lcs_str = str1[i-1] + lcs_str;
                --i;
                --j;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1])  //向左走
                    --i;
                else if(dp[i-1][j] < dp[i][j-1])  //向上走
                    --j;
                //此时向上向右均为LCS的元素
                else{
                    PrintAllLCS(str1, str2, i-1, j, lcs_str);
                    PrintAllLCS(str1, str2, i, j-1, lcs_str);
                    return;
                }
            }
        }
        all_lcs.insert(lcs_str);
    }
    vector<vector<int> > dp;
    set<string> all_lcs;
};


/*
求两个字符串的最长公共子串，要求子串连续

输入例子1:
bab
caba

输出例子1:
2
*/

/*
当str1[i-1] == str2[j-1]时，子序列长度dp[i][j] = dp[i - 1][j - 1] + 1；
只是当str1[i-1] ！= str2[j-1]时，dp[i][j]要为0，而不是max{dp[i - 1][j], dp[i][j - 1]}。
*/
int Longest_Common_Substring(string& str1, string& str2){
    int m = str1.size(), n = str2.size();
    int res = 0;
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = 0;
            if(res < dp[i][j])
                res = dp[i][j];
        }
    }
    return res;
}

int main()
{
    string s1 = "abcfbc";
    string s2 = "abfcab";
    string s3 = "programming";
    string s4 = "contest";
    Solution fir;
    string lcs_str;
    int res = fir.lengthOflongestCommonSequence(s1, s2);
    cout << res << endl;
    fir.PrintAllLCS(s1, s2, s1.length(), s2.length(), lcs_str);
    set<string>::iterator iter = fir.all_lcs.begin();
	while (iter != fir.all_lcs.end()) {
		cout << *iter++ << endl;
	}
    return 0;
}