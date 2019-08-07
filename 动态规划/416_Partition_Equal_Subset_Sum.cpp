/*
给定非空数组，其元素均为正整数，问是否可以将数组分成两部分，每部分的元素和相等

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Example 1:
Input: [1, 5, 11, 5]
Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: [1, 2, 3, 5]
Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
典型的背包问题，在n个物品中选出一定物品，填满sum/2的背包
F(n, C)考虑将n个物品填满容量为C的背包
F(i, C) = F(i - 1, C) || F(i - 1, C - w(i))

时间复杂度为O(n*sum/2) = O(n * sum)
限制条件：最多有200个数字，每个数字最大为100，所有数字和最大为20000
背包最大为10000，n*sum/2 = 100 * 10000 = 100万
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        memo = vector<vector<int> >(nums.size(), vector<int>(sum / 2 + 1, -1));
        return tryPartition(nums, nums.size() - 1, sum / 2);
    }
private:
    //memo[i][C]表示使用索引为[0...i]的这些元素，是否可以填充一个容量为C的背包
    //-1表示未计算；0表示不可以填充；1表示可以填充
    vector<vector<int> > memo;
    //用[0...index]的物品，填冲容量为sum的背包
    bool tryPartition(const vector<int>& nums, int index, int sum){
        if(sum == 0){
            return true;
        }
        if(sum < 0 || index < 0){
            return false;
        }
        if(memo[index][sum] != -1){
            return memo[index][sum] == 1;
        }
        memo[index][sum] = (tryPartition(nums, index - 1, sum) || 
                            tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;
        return memo[index][sum];
    }
};

//动态规划
class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int n = nums.size(), C = sum / 2;
        vector<bool> memo(C + 1, false);
        for(int i = 0; i <= C; ++i){
            memo[i] = (nums[0] == i);
        }
        for(int i = 1; i < n; ++i){
            for(int j = C; j >= nums[i]; --j){
                memo[j] = memo[j] || memo[j - nums[i]];
            }
        }
        return memo[C];
    }
};