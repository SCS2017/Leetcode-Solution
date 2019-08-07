/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

示例:
现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

/*
设查找的数为y，每次都与最右上角的数比较，第一行最后一列的数为x，
如果x<y，则第一行的所有的数都小于y，删掉第一行
如果x>y，则最后一列所有的数都大于y，删掉最后列
时间复杂度O(m+n)=O(max(m, n))
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        for(int r=0, c=n-1; (r<m) && (c>=0);){
            if(matrix[r][c] > target){
                --c;
            }
            else if(matrix[r][c] < target){
                ++r;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

/*
分治法
将矩阵分为四块  A   B
然后          C   D
取中心点x，要查找元素为y
如果x < y，则y不可能在A
如果x > y，则y不可能在D
时间复杂度T(N) = T(N/2) + T(N/4) +O(1)
*/
class Solution1 {
public:
    bool find(vector<vector<int> >&a, int x1, int y1, int x2, int y2, int target){
        if (x1 > x2 || y1 > y2){
            return false;
        }
        int midx = (x1 + x2) >> 1;
        int midy = (y1 + y2) >> 1;
        if(target == a[midx][midy]){
            return true;
        }
        return (target < a[midx][midy]) ?
        (find(a, x1, y1, midx-1, y2, target) || find(a, midx, y1, x2, midy-1, target)):
        (find(a, x1, midy+1, x2, y2, target) || find(a, midx+1, y1, x2, midy, target));
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        return find(matrix, 0, 0, m-1, n-1, target);
    }
};

int main()
{
    int m, n;
    cout << "input the size of matrix:";
    cin >> m >> n;
    vector<vector<int> > matrix(m, vector<int>(n));
    cout << "input a matrix: " << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    int target;
    bool result;
    Solution first;
    cout << "input a target: ";
    cin >> target;
    result = first.searchMatrix(matrix, target);
    cout << boolalpha << result << endl;
    return 0;
}