/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:
输入:
11110
11010
11000
00000
输出: 1

示例 2:
输入:
11000
11000
00100
00011
输出: 3
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
经典连通分量问题
图是什么？
  节点：所有1的位置
  边：两个相邻的1的位置有一条边
DFS/BFS
  选一个没标记的点，然后搜索，扩展4个邻居(如果有)，直到不能扩展
  每一次是一个连通分量
  难点：标记节点————判重
*/

//DFS
class Solution {
public:
    void help(vector<vector<char>>& a, int x, int y){
        if((x < 0) || (x >= a.size()) || (y < 0) || (y >= a[x].size()) || a[x][y] != '1'){
            return;
        }
        //标记，因为数组中只有'1'和'0'，所以这里直接标记成'0'，常规解法还是使用布尔数组来标记
        //如果题目中不允许改变原始数组a，可以最后再变回去
        a[x][y] = '0'; 
        help(a, x - 1, y);
        help(a, x + 1, y);
        help(a, x, y - 1);
        help(a, x, y + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
       int answer = 0;
       for(int i = 0; i < grid.size(); ++i){
           for(int j = 0; j < grid[i].size(); ++j){
               if(grid[i][j] == '1'){
                   help(grid, i, j);
                   ++answer;
               }
           }
       }
       return answer;
    }
};

//DFS
class Solution11 {
public:
    int numIslands(vector<vector<char>>& grid) {
       int answer = 0;
       m = grid.size();
       if(m == 0){
           return 0;
       }
       n = grid[0].size();
       visited = vector<vector<bool>>(m, vector<bool>(n, false));
       for(int i = 0; i < m; ++i){
           for(int j = 0; j < n; ++j){
               if(grid[i][j] == '1' && !visited[i][j]){
                   ++answer;
                   dfs(grid, i, j);
               }
           }
       }
       return answer;
    }
private:
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
    vector<vector<bool>> visited;
    bool InArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    //从grid[x][y]位置开始，进行floodfill
    //保证(x, y)合法，且grid[x][y]是没有被访问过的陆地
    void dfs(vector<vector<char>>& grid, int x, int y){
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(InArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1'){
                dfs(grid, newx, newy);
            }
        }
        return;
    }
};

//BFS
class Solution2 {
public:
    void help(vector<vector<char>>& a, int x, int y){
        queue<pair<int, int> > q;
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        a[x][y] = '0';
        for(q.push(make_pair(x, y)); !q.empty(); q.pop()){
            x = q.front().first;
            y = q.front().second;
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if((nx >= 0) && (nx < a.size()) && (ny >= 0) && (ny < a[nx].size()) && (a[nx][ny] == '1')){
                    a[nx][ny] = '0';
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
       int answer = 0;
       for(int i = 0; i < grid.size(); ++i){
           for(int j = 0; j < grid[i].size(); ++j){
               if(grid[i][j] == '1'){
                   help(grid, i, j);
                   ++answer;
               }
           }
       }
       return answer;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[i].size(); ++j){
            cin >> grid[i][j];
        }
    }
    Solution fir;
    int res = fir.numIslands(grid);
    cout << res << endl;
    return 0;
}