/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:
Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int> > dp(rows, vector<int>(cols, 0));
        int cnt = 0;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                cnt = max(cnt, dfs(matrix, i, j, dp));
            }
        }
        return cnt;
    }
private:
    int dfs(vector<vector<int> >& matrix, int row, int col, vector<vector<int> >& dp){
        int rows = matrix.size(), cols = matrix[0].size();
        if(dp[row][col])
            return dp[row][col];
        vector<vector<int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto &dir: dirs){
            int x = row + dir[0], y = col + dir[1];
            if(x < 0 || x >= rows || y < 0 || y >= cols)
                continue;
            if(matrix[x][y] <= matrix[row][col])
                continue;
            dp[row][col] = max(dp[row][col], dfs(matrix, x, y, dp));
        }
        return ++dp[row][col];
    }
};

int main(){
    int m, n;
    while(cin >> m >> n){
        vector<vector<int> > matrix(m, vector<int>(n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                cin >> matrix[i][j];
            }
        }
        int res = Solution().longestIncreasingPath(matrix);
        cout << res << endl;
    }
    return 0;
}
