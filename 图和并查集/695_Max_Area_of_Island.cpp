/*
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。
你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:
[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。
*/

#include <bits/stdc++.h>

using namespace std;

//DFS
class Solution {
public:
    int maxSize(vector<vector<int>>& grid , int i , int j){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        int tmp = 0;
        if(grid[i][j] == 1){
            tmp = 1;
            grid[i][j] = 0;
        }
        else
            return 0;
        return tmp + maxSize(grid,i+1,j) + maxSize(grid,i,j+1) + maxSize(grid,i-1,j) + maxSize(grid,i,j-1);
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0 ; i < grid.size() ; i ++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                res = max(res, maxSize(grid,i,j));
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 1){
                    continue;
                }
                int tmp = 0;
                dfs(grid, i, j, tmp, res);
            }
        }
        return res;
    }
private:
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& grid, int i, int j, int& tmp, int& res){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return;
        res = max(res, ++tmp);
        grid[i][j] = 0;
        for(auto dir: dirs){
            dfs(grid, i+dir[0], j+dir[1], tmp, res);
        }
    }
};
