/*
最长上升子序列的长度
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <iostream>
#include <vector>

using namespace std;

//子序列可以是不连续的
//LIS(i)表示以第i个数字为结尾的最长上升子序列的长度
//LIS(i)表示[0...i]的范围内，选择数字nums[i]可以获得的最长上升子序列的长度
//LIS(i) = max(j < i) (1 + LIS(j) if nums[i] > nums[j])

//  10  9  2  5  3  7  101  18
//  1   1  1  1  1  1   1   1
//            2  2  3   4   4
//不过这个样例会让我们产生错觉：是不是最后的结果就是数组的最后一个元素
//还有就是是不是找到前面比这个数小的数，然后将对应数组的值+1即可呢
//很容易找到一个反例
// 10  15  20  11  9  101
// 1   2   3   2   1   4 
//前面的所有数字都要扫描一下
//时间复杂度O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        //memo(i)表示以第i个数字为结尾的最长上升子序列的长度
        vector<int> memo(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    memo[i] = max(memo[i], 1 + memo[j]);
                }
            }
        }
        int res = 1;
        //扫描一遍memo，寻找最大值
        for(int i = 0; i < memo.size(); ++i){
            res = max(res, memo[i]);
        }
        return res;
    }
};

/* 
下面来看一种优化时间复杂度到 O(nlgn) 的解法，这里用到了二分查找法。
思路是，先建立一个数组 ends，把首元素放进去，然后比较之后的元素，如果遍历到的新元素比 ends 数组中的首元素小的话，
替换首元素为此新元素，如果遍历到的新元素比ends数组中的末尾元素还大的话，将此新元素添加到ends数组末尾(注意不覆盖原末尾元素)。
如果遍历到的新元素比 ends 数组首元素大，比尾元素小时，此时用二分查找法找到第一个不小于此新元素的位置，覆盖掉位置的原来的数字，
以此类推直至遍历完整个 nums 数组，此时 ends 数组的长度就是要求的LIS的长度，
特别注意的是 ends 数组的值可能不是一个真实的 LIS，比如若输入数组 nums 为 {4, 2， 4， 5， 3， 7}，
那么算完后的 ends 数组为 {2， 3， 5， 7}，可以发现它不是一个原数组的 LIS，只是长度相等而已，千万要注意这点。
*/
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> dp{nums[0]};
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < dp[0])
                dp[0] = nums[i];
            else if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            else{
                int left = 0, right = dp.size();
                while(left < right){
                    int mid = left + (right - left) / 2;
                    if(dp[mid] < nums[i])
                        left = mid + 1;
                    else
                        right = mid;
                }
                dp[right] = nums[i];
            }
        }
        return dp.size();
    }
};

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 4};
    int len = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + len);
    int res = Solution1().lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}