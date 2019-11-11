/* 
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
感谢 Marcos 贡献此图。

示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

#include <bits/stdc++.h>
using namespace std;

/* 
1. 找出最高点
2. 分别从两边往最高点遍历：如果下一个数比当前数小，说明可以接到水
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int res = 0, n = height.size();
        int maxHeight = 0, maxHeightIndex = 0;
        for(int i = 0; i < n; ++i){
            if(height[i] > maxHeight){
                maxHeight = height[i];
                maxHeightIndex = i;
            }
        }
        int tmp = height[0];
        for(int i = 0; i < maxHeightIndex; ++i){
            if(height[i] > tmp)
                tmp = height[i];
            else
                res += tmp - height[i];
        }
        tmp = height.back();
        for(int i = n-1; i > maxHeightIndex; --i){
            if(height[i] > tmp)
                tmp = height[i];
            else
                res += tmp - height[i];
        }
        return res;
    }
};

/* 双指针
left和right两个指针分别指向数组的首尾位置，从两边向中间扫描，在当前两指针确定的范围内，先比较两头找出较小值，
如果较小值是left指向的值，则从左向右扫描，如果较小值是right指向的值，则从右向左扫描，若遇到的值比当较小值小，
则将差值存入结果，如遇到的值大，则重新确定新的窗口范围，以此类推直至left和right指针重合
*/
class Solution1 {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while(l < r){
            int mn = min(height[l], height[r]);
            if(mn == height[l]){
                ++l;
                while(l < r && height[l] < mn)
                    res += mn - height[l++];
            }
            else{
                --r;
                while(l < r && height[r] < mn)
                    res += mn - height[r--];
            }
        }
        return res;
    }
};


/*使用栈 
遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，注意我们不直接把高度压入栈，而是把坐标压入栈，
这样方便我们在后来算水平距离。当我们遇到比栈顶高度大的时候，就说明有可能会有坑存在，可以装雨水。
此时我们栈里至少有一个高度，如果只有一个的话，那么不能形成坑，我们直接跳过，如果多余一个的话，那么此时把栈顶元素取出来当作坑，
新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，
二者相乘就是盛水量啦
*/
class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0, n = height.size();
        while(i < n){
            if(st.empty() || height[i] <= height[st.top()])
                st.push(i++);
            else{
                int t = st.top();
                st.pop();
                if(st.empty())
                    continue;
                res += (min(height[i], height[st.top()]) - height[t]) * (i - st.top() - 1);
            }
        }
        return res;
    }
};


int main(){
    vector<int> arr{0,1,0,2,1,0,1,3,2,1,2,1};
    int res = Solution().trap(arr);
    cout << res << endl;
    return 0;
}
