/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的
防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:
输入: [1,2,3,1]
输出: 4
解释: 偷窃1号房屋 (金额 = 1) ，然后偷窃3号房屋 (金额 = 3)。偷窃到的最高金额 = 1 + 3 = 4 。

示例 2:
输入: [2,7,9,3,1]
输出: 12
解释: 偷窃1号房屋 (金额 = 2), 偷窃3号房屋 (金额 = 9)，接着偷窃5号房屋 (金额 = 1)。偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/

#include <iostream>
#include <vector>

using namespace std;

/*
们维护一个一位数组dp，其中dp[i]表示到i位置时不相邻数能形成的最大和，那么状态转移方程怎么写呢，
我们先拿一个简单的例子来分析一下，比如说nums为{3, 2, 1, 5}，那么我们来看我们的dp数组应该是什么样的，
首先dp[0]=3没啥疑问，再看dp[1]是多少呢，由于3比2大，所以我们抢第一个房子的3，当前房子的2不抢，
所以dp[1]=3，那么再来看dp[2]，由于不能抢相邻的，所以我们可以用再前面的一个的dp值加上当前的房间值，
和当前房间的前面一个dp值比较，取较大值当做当前dp值，所以我们可以得到
状态转移方程dp[i] = max(num[i] + dp[i - 2], dp[i - 1]), 
由此看出我们需要初始化dp[0]和dp[1]，其中dp[0]即为num[0]，dp[1]应该为max(num[0], num[1])，
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n-1];
    }
};

class Solution1 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        //对状态的定义
        //memo[i]表示考虑抢劫nums[i...n-1]所能获得的最大收益
        vector<int> memo(n, -1);
        memo[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; --i){
            for(int j = i; j < n; j++){
                memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0));
            }
        }
        return memo[0];
    }
};

class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> memo(n, -1);
        //memo[i]表示考虑抢劫nums[0...i]所能获得的最大收益
        memo[0] = nums[0];
        for(int i = 1; i < n; ++i){
            for(int j = i; j >= 0; --j){
                memo[i] = max(memo[i], nums[j] + (j - 2 >= 0 ? memo[j - 2] : 0));
            }
        }
        return memo[n - 1];
    }
};

int main()
{
    int n;
    while(cin >> n){
        vector<int> nums(n);
        for(int i = 0; i < nums.size(); ++i){
            cin >> nums[i];
        }
        Solution1 fir;
        int res = fir.rob(nums);
        cout << res << endl;
    }
    return 0;
}