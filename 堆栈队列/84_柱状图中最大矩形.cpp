/* 
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。


示例:
输入: [2,1,5,6,2,3]
输出: 10
*/

#include <bits/stdc++.h>
using namespace std;

/* 
遍历数组，每找到一个局部峰值（只要当前的数字大于后面的一个数字，那么当前数字就看作一个局部峰值，跟前面的数字大小无关），
然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (i + 1 < height.size() && height[i] <= height[i + 1]) {
                continue;
            }
            int minH = height[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, height[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }
};

/* 递减栈
我们需要按从高板子到低板子的顺序处理，先处理最高的板子，宽度为1，然后再处理旁边矮一些的板子，此时长度为2，
因为之前的高板子可组成矮板子的矩形 ，因此我们需要一个递增栈，当遇到大的数字直接进栈，而当遇到小于栈顶元素的数字时，
就要取出栈顶元素进行处理了，那取出的顺序就是从高板子到矮板子了，于是乎遇到的较小的数字只是一个触发，
表示现在需要开始计算矩形面积了，为了使得最后一块板子也被处理，这里用了个小 trick，
在高度数组最后面加上一个0，这样原先的最后一个板子也可以被处理了
*/
class Solution {
public:
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

int main(){
    
    return 0;
}
