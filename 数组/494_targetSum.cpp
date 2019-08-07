/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。
对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:
输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5

解释: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
一共有5种方法让最终目标和为3。

注意:
数组的长度不会超过20，并且数组中的值全为正数。
初始的数组的和不会超过1000。
保证返回的最终结果为32位整数。
*/

#include <bits/stdc++.h>

using namespace std;

//递归，会超时
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        helper(nums, S, 0, res);
        return res;
    }
    void helper(vector<int>& nums, int S, int start, int& res){
        if(start >= nums.size()){
            if(S == 0){
                ++res;
            }
            return;
        }
        helper(nums, S - nums[start], start + 1, res);
        helper(nums, S + nums[start], start + 1, res);
    }
};

class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> dp(nums.size());
        return helper(nums, S, 0, dp);
    }
    int helper(vector<int>& nums, long sum, int start, vector<unordered_map<int, int>>& dp){
        if(start == nums.size()){
            return sum == 0;
        }
        if(dp[start].count(sum)){
            return dp[start][sum];
        }
        int cnt1 = helper(nums, sum - nums[start], start + 1, dp);
        int cnt2 = helper(nums, sum + nums[start], start + 1, dp);
        return dp[start][sum] = cnt1 + cnt2;
    }
};

//我们也可以使用迭代的方法来解，还是要用dp数组，其中dp[i][j]表示到第i-1个数字且和为j的情况总数
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (auto &a : dp[i]) {
                int sum = a.first, cnt = a.second;
                dp[i + 1][sum + nums[i]] += cnt;
                dp[i + 1][sum - nums[i]] += cnt;
            }
        }
        return dp[n][S];
    }
};

int main()
{
    vector<int> arr;
    int num, target;
    while(cin >> num){
        arr.push_back(num);
        if(cin.get() == '\n')
            break;
    }
    cin >> target;
    int res = Solution().findTargetSumWays(arr, target);
    cout << res << endl;
    return 0;
}