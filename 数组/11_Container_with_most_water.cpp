/*
给定 n 个非负整数 a_1，a_2，...，a_n，每个数代表坐标中的一个点 (i, a_i) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, a_i) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

#include <iostream>
#include <vector>

using namespace std;

/*
暴力搜索，竟然能通过
*/
class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for(int i = 0; i < height.size(); ++i){
            for(int j = i + 1; j < height.size(); ++j){
                res = max(res, min(height[i], height[j]) * (j - i)); 
            }
        }
        return res;
    }
};

/*
用两个指针从两端开始向中间靠拢，如果左端线段短于右端，那么左端右移，反之右端左移，直到左右两端移到中间重合，
记录这个过程中每一次组成木桶的容积，返回其中最大的。
每次移动两者中较小的那个数对应的指针

合理性解释：当左端线段L小于右端线段R时，我们把L右移，这时舍弃的是L与右端其他线段（R-1, R-2, ...）组成的木桶，
这些木桶是没必要判断的，因为这些木桶的容积肯定都没有L和R组成的木桶容积大。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while(i < j){
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? ++i : --j;
        } 
        return res;
    }
};

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> height(n);
        for(int i = 0; i < height.size(); ++i)
        {
            cin >> height[i];
        }
        Solution fir;
        int res = fir.maxArea(height);
        cout << res << endl;
    }
}