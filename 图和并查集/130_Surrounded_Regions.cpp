/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X

解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
*/

/*
解答
方法同岛屿的个数，利用图的 DFS，因为与边界上的'O'相连的'O'都不会被填充，我们首先遍历二维矩阵的边界上的字符，
如果字符为'O'，则从这个位置开始在二维矩阵中进行 DFS，将相连的所有'O'(包括自己)都填充为'$'。
此时二维矩阵中剩下的'O'都需要被填充为'X'，我们遍历二维矩阵，遇到'O'就将它填充为'X'。
最后，将二维矩阵中的'$'恢复到'O'即可。

设二维矩阵的行数为m，列数为n
时间复杂度：O(mn) 空间复杂度：O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        int rows = board.size(), cols = board[0].size();
        int i = 0, j = 0;
        for(; j < cols; ++j){
            if(board[i][j] == 'O')
                dfs(i, j, board);
        }
        j = cols - 1;
        for(; i < rows; ++i){
            if(board[i][j] == 'O')
                dfs(i, j, board);
        }
        i = rows - 1;
        for(; j >= 0; --j){
            if(board[i][j] == 'O')
                dfs(i, j, board);
        }
        j = 0;
        for(; i >= 0; --i){
            if(board[i][j] == 'O')
                dfs(i, j, board);
        }
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
    }
private:
    void dfs(int row, int col, vector<vector<char>>& board){
        int rows = board.size(), cols = board[0].size();
        if(row < 0 || row > rows || col < 0 || col > cols || board[row][col] != 'O')
            return;
        board[row][col] = '$';
        dfs(row+1, col, board);
        dfs(row-1, col, board);
        dfs(row, col+1, board);
        dfs(row, col-1, board);
    }
};

int main(){
   
   return 0;
}
