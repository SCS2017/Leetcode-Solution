/*
给定m*n的网格，均由非负的数填充，找到从最左上到最右下的最小路径和
注意：在任意一点，只能向右或者向下移动

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

#include <iostream>
#include <vector>

using namespace std;

/*动态规划
dp[i][j]表示从左上角到达(i, j)的最小值
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j]
初值
dp[0][0] = a[0][0]
dp[0][j>0] = dp[0][j-1] + a[0][j]
dp[i>0][0] = dp[i-1][0] + a[i][0]
复杂度：时间O(m*n)，空间O(m*n)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < n; ++j){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    int tmp;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> grid[i][j];
        }
    }
    cout << endl;
    for(vector<vector<int>>::iterator it = grid.begin(); it != grid.end(); ++it){
        vector<int> tmp = *it;
        for(vector<int>::iterator itt = tmp.begin(); itt != tmp.end(); ++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
    Solution fir;
    int res;
    res = fir.minPathSum(grid);
    cout << res << endl;
    return 0;
}
