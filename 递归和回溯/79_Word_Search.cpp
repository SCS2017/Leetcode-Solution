/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasPathCore(vector<vector<char>>& board, int row, int col, string word, int pathLength, vector<vector<bool>>& visited){
        int rows = board.size();
        int cols = board[0].size();
        if(word.size() == pathLength){
            return true;
        }
        if(row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] != word[pathLength] || visited[row][col]){
            return false;
        }
        visited[row][col] = true;
        bool res = hasPathCore(board, row, col - 1, word, pathLength + 1, visited) || 
              hasPathCore(board, row, col + 1, word, pathLength + 1, visited) ||
              hasPathCore(board, row - 1, col, word, pathLength + 1, visited) ||
              hasPathCore(board, row + 1, col, word, pathLength + 1, visited);       
        visited[row][col] = false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        if(board.empty() || board[0].empty()){
            return false;
        }
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        int pathLength = 0;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++ col){
                if(hasPathCore(board, row, col, word, 0, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution1 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(searchWord(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;
    vector<vector<bool>> visited;
    bool InArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    //从board[starx][starty]开始，寻找Word[ index...word.size()]
    bool searchWord(const vector<vector<char>>& board, const string& word, int index, int startx, int starty){
        if(index == word.size() - 1){
            return board[startx][starty] == word[index];
        }
        if(board[startx][starty] == word[index]){
            visited[startx][starty] = true;
            //从startx, starty出发，向四个方向寻找
            for(int i = 0; i < 4; ++i){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if(InArea(newx, newy) && !visited[newx][newy] && searchWord(board, word, index + 1, newx, newy)){
                        return true;
                }
            }
            visited[startx][starty] = false;
        }
        return false;
    }
};