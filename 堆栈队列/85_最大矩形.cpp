/* 
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:
输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6
*/

#include <bits/stdc++.h>
using namespace std;

/* 
此题是之前那道的 Largest Rectangle in Histogram 的扩展，这道题的二维矩阵每一层向上都可以看做一个直方图，
输入矩阵有多少行，就可以形成多少个直方图，对每个直方图都调用 Largest Rectangle in Histogram 中的方法，
就可以得到最大的矩形面积。那么这道题唯一要做的就是将每一层都当作直方图的底层，并向上构造整个直方图，
由于题目限定了输入矩阵的字符只有 '0' 和 '1' 两种，所以处理起来也相对简单。
方法是，对于每一个点，如果是 ‘0’，则赋0，如果是 ‘1’，就赋之前的 height 值加上1。
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0;
        vector<int> height;
        for(int i = 0; i < matrix.size(); ++i){
            height.resize(matrix[i].size());
            for(int j = 0; j < matrix[i].size(); ++j){
                height[j] = (matrix[i][j] == '0' ? 0 : (1 + height[j]));
            }
            // for(int i = 0; i < height.size(); ++i)
            //     cout << height[i] << " ";
            // cout << endl;
            // 1 0 1 0 0 
            // 2 0 2 1 1 
            // 3 1 3 2 2 
            // 4 0 0 3 0 
            res = max(res, largestRectangleArea(height));
        }
        return res;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); ++i){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int cur = st.top();
                st.pop();
                res = max(res, heights[cur] * (st.empty() ? i: (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};


/* 
下面这种方法的思路很巧妙，height 数组和上面一样，
这里的left数组表示若当前位置是1且与其相连都是1的左边界的位置（若当前 height 是0，则当前 left 一定是0），
right 数组表示若当前位置是1且与其相连都是1的右边界的位置再加1（加1是为了计算长度方便，直接减去左边界位置就是长度），
初始化为n（若当前 height 是0，则当前 right 一定是n），
那么对于任意一行的第j个位置，矩形为 (right[j] - left[j]) * height[j]，我们举个例子来说明，比如给定矩阵为：
[
  [1, 1, 0, 0, 1],
  [0, 1, 0, 0, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 0, 0, 1]
]

第0行：
h: 1 1 0 0 1
l: 0 0 0 0 4
r: 2 2 5 5 5 

第1行：
h: 0 2 0 0 2
l: 0 1 0 0 4
r: 5 2 5 5 5 

第2行：
h: 0 0 1 1 3
l: 0 0 2 2 4
r: 5 5 5 5 5
 
第3行：
h: 0 0 2 2 4
l: 0 0 2 2 4
r: 5 5 5 5 5

第4行：
h: 0 0 0 0 5
l: 0 0 0 0 4
r: 5 5 5 5 5 
*/

class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for(int i = 0; i < m; ++i){
            int cur_left = 0, cur_right = n;
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '1'){
                    ++height[j];
                    left[j] = max(left[j], cur_left);
                }
                else{
                    height[j] = 0;
                    left[j] = 0;
                    cur_left = j+1;
                }
            }
            for(int j = n-1; j >= 0; --j){
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j], cur_right);
                }
                else{
                    right[j] = n;
                    cur_right = j;
                }
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
};

int main(){
    vector<vector<char> > matrix{{'1','0','1','0','0'},
                                 {'1','0','1','1','1'},
                                 {'1','1','1','1','1'},
                                 {'1','0','0','1','0'}};
    int res = Solution().maximalRectangle(matrix);
    cout << res << endl;
    return 0;
}
