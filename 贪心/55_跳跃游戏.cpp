/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。

示例 1:
输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。

示例 2:
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/

#include <bits/stdc++.h>

using namespace std;

/*动态规划
从后往前分析，首先判断倒数第二个元素是否可以到达最后一个元素，如果可以，将不再考虑最后一个元素。
然后往前递推，如果都能跳到的话，最后分析的就是第一个元素能否跳到第二个元素
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return false;
        vector<bool> dp(nums.size());
        dp[0] = true;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j] && nums[j] + j >= i){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};

/*贪心
我们记录一个的坐标代表当前可达的最后节点，这个坐标初始等于nums.length-1， 
然后我们每判断完是否可达，都向前移动这个坐标，直到遍历结束。

如果这个坐标等于0，那么认为可达，否则不可达。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return false;
        int last_position = nums.size() - 1;
        for(int i = nums.size()-1; i >= 0; --i){
            if(nums[i] + i >= last_position)
                last_position = i;
        }
        return last_position == 0;
    }
};

int main(){
    
    return 0;
}
