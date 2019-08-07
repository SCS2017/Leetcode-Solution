/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？

说明：m 和 n 的值均不超过 100。

示例 1:
输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右

示例 2:
输入: m = 7, n = 3
输出: 28

*/
#include <iostream>
#include <vector>

using namespace std;

/*动态规划
状态方程为 dp[i][j] = dp[i-1][j] + dp[i][j-1]
初值为 dp[0][0] = 0, dp[i][0] = 1, dp[0][j] = 1
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1){
            return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = 0;
        for(int i = 1; i < m; ++i){
            dp[i][0] = 1;
        }
        for(int j = 1; j < n; ++j){
            dp[0][j] = 1;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    int m, n;
    while(cin >> m >> n){
        Solution fir;
        int res = fir.uniquePaths(m, n);
        cout << res << endl;
    }
    return 0;
}