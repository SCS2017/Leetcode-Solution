/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。
少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。
相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，
第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。 
通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:
输入: [1,7,4,9,2,5]
输出: 6 
解释: 整个序列均为摆动序列。

示例 2:
输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。

示例 3:
输入: [1,2,3,4,5,6,7,8,9]
输出: 2

进阶:
你能否用 O(n) 时间复杂度完成此题?
*/

#include <iostream>
#include <vector>
using namespace std;

/*方法1：动态规划
开辟两个数组dp1和dp2，其中dp[i]表示到位置i时包含的以正差值结尾的摆动子序列的最大长度，
dp2[i]表示到位置i时包含的以负差值结尾的摆动子序列的最大长度，
我们从i=1开始遍历数组，然后对于每个遍历到的数字，再从开头位置遍历到这个数字，
然后比较nums[i]和nums[j]，分别更新对应的位置。

动态转移方程：
dp1[i] = max{dp2[j]+1 , 0 =< j <= i-1 且 nums[i] > nums[j]} 
dp2[i] = max{dp1[j]+1 , 0 =< j <= i-1 且 nums[i] > nums[j]}
遍历结束之后，整个数组的最长摆动子序列就是max(dp1.back(),dp2.back())。

时间复杂度O(n2) 空间复杂度O(n)

*/

class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        vector<int> dp1(nums.size(), 1);
        vector<int> dp2(nums.size(), 1);
        for(int i = 1; i < nums.size();i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) 
                    dp1[i] = max(dp1[i], dp2[j] + 1);
                else if (nums[i] < nums[j]) 
                    dp2[i] = max(dp2[i], dp1[j] + 1);
            }
        }
        
        return max(dp1.back(), dp2.back());
    }
};

/*方法2：贪心法
基于动态规划的方法，优化空间，改用两个变量p和q，p表示遍历到当前元素num[i]以正差值结尾的摆动子序列的最大长度，
q表示遍历到当前元素num[i]以负差值结尾的摆动子序列的最大长度。分两种情况处理：
当num[i] > num[i-1]时，令p = q+1；
当num[i] < num[i-1]时，令q = p+1。

遍历结束之后，整个数组的最长摆动子序列就是max(p,q)。

时间复杂度O(n) 空间复杂度O(1)

*/
class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int p = 1, q = 1;
        if(nums.size() <= 1)
            return nums.size();
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i - 1])
                p = q + 1;
            else if(nums[i] < nums[i - 1])
                q = p + 1;
        }
        return max(p, q);
    }
};