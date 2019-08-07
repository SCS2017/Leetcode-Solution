/*
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。现在要求你戳破所有的气球。
每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 
这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:
你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:
Input: [3,1,5,8]
Output: 167 

Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

/*
解法：动态规划
dp[i][j]表示[i-1]和[j+1]("边界")不变，把[i...j]之间的气球全部打掉的最大得分
最终结果dp[0][n-1]
枚举最后一个打掉的气球k，[i, k-1]得分是最优的，[k+1, j]得分是最优的
打掉k的得分 nums[i-1]*nums[k]*nums[j+1]
方程：dp[i][j] = max(dp[i][k-1] + dp[k+1][j]) + nums[i-1]*nums[k]*nums[j+1]
时间复杂度O(n^3)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<vector<int> > dp(n, vector<int>(n));
        //枚举长度为len的滑窗[i, j]
        for(int len = 1; len <= n; ++len){
            for(int i = 0; (i + len) <= n; ++i){
                int j = i + len - 1;
                for(int k = i; k <= j; ++k){
                    dp[i][j] = max(dp[i][j], ((i <= k-1) ? dp[i][k-1] : 0) + ((k+1 <= j) ? dp[k+1][j] : 0) 
                                + ((i-1 >=0) ? nums[i-1]: 1) * nums[k] * ((j+1 < n) ? nums[j+1] : 1));
                }
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    Solution first;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<arr.size(); ++i){
        cin >> arr[i];
    }
    int result;
    result = first.maxCoins(arr);
    cout << result << endl;
    return 0;
}