/* 
给定一个表示分数的非负整数数组。 玩家1从数组任意一端拿取一个分数，随后玩家2继续从剩余数组任意一端拿取分数，然后玩家1拿，……。
每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。
给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。

示例 1:
输入: [1, 5, 2]
输出: False
解释: 一开始，玩家1可以从1和2中进行选择。
如果他选择2（或者1），那么玩家2可以从1（或者2）和5中进行选择。如果玩家2选择了5，那么玩家1则只剩下1（或者2）可选。
所以，玩家1的最终分数为 1 + 2 = 3，而玩家2为 5。
因此，玩家1永远不会成为赢家，返回 False。

示例 2:
输入: [1, 5, 233, 7]
输出: True
解释: 玩家1一开始选择1。然后玩家2必须从5和7中进行选择。无论玩家2选择了哪个，玩家1都可以选择233。
最终，玩家1（234分）比玩家2（12分）获得更多的分数，所以返回 True，表示玩家1可以成为赢家。

注意:
1 <= 给定的数组长度 <= 20.
数组里所有分数都为非负数且不会大于10000000。
如果最终两个玩家的分数相等，那么玩家1仍为赢家。
*/

#include <bits/stdc++.h>

using namespace std;

/* 
我们需要一个变量来标记当前是第几个玩家，还需要两个变量来分别记录两个玩家的当前数字和，在递归函数里面，如果当前数组为空了，
我们直接比较两个玩家的当前得分即可，如果数组中只有一个数字了，我们根据玩家标识来将这个数字加给某个玩家并进行比较总得分。
如果数组有多个数字，我们分别生成两个新数组，一个是去掉首元素，一个是去掉尾元素，然后根据玩家标识分别调用不同的递归，
只要下一个玩家两种情况中任意一种返回false了，那么当前玩家就可以赢了
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, 0, 1);
    }
    bool canWin(vector<int> nums, int sum1, int sum2, int player) {
        if (nums.empty()) return sum1 >= sum2;
        if (nums.size() == 1) {
            if (player == 1) return sum1 + nums[0] >= sum2;
            else if (player == 2) return sum2 + nums[0] > sum1;
        }
        vector<int> va = vector<int>(nums.begin() + 1, nums.end());
        vector<int> vb = vector<int>(nums.begin(), nums.end() - 1);
        if (player == 1) {
            return !canWin(va, sum1 + nums[0], sum2, 2) || !canWin(vb, sum1 + nums.back(), sum2, 2);
        } else if (player == 2) {
            return !canWin(va, sum1, sum2 + nums[0], 1) || !canWin(vb, sum1, sum2 + nums.back(), 1);
        }
    }
};

/* 
我们还可以使用DP加Minimax的方法来做，先来看递归的写法，十分的简洁。
DP数组的作用是保存中间结果，再次遇到相同情况时直接返回不用再次计算，提高了运算效率
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return canWin(nums, 0, n - 1, dp) >= 0;
    }
    int canWin(vector<int>& nums, int s, int e, vector<vector<int>>& dp) {
        if (dp[s][e] == -1) {
            dp[s][e] = (s == e) ? nums[s] : max(nums[s] - canWin(nums, s + 1, e, dp), nums[e] - canWin(nums, s, e - 1, dp));
        }
        return dp[s][e];
    }
};

/* 
迭代写法
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
        for (int len = 1; len < n; ++len) {
            for (int i = 0, j = len; j < n; ++i, ++j) {
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};

