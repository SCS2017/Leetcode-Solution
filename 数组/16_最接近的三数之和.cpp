/* 
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int res=accumulate(nums.begin(), nums.begin() + 3, 0);
        int diff = abs(res - target);
        for(int i = 0; i < nums.size(); ++i){
            int left = i+1, right = nums.size() - 1;
            int tmp = target - nums[i];
            while(left < right){
                if(nums[left] + nums[right] == tmp)
                    return target;
                else{
                    if(abs(nums[left] + nums[right] - tmp) < diff){
                        diff = abs(nums[left] + nums[right] - tmp);
                        res = nums[i] + nums[left] + nums[right];
                    }
                    else if(nums[left] + nums[right] < tmp)
                        ++left;
                    else
                        --right;
                } 
                    
            }
        }
        return res;
    }
};

/* 
我们要保证当前三数和跟给定值之间的差的绝对值最小，所以我们需要定义一个变量 diff 用来记录差的绝对值，
然后我们还是要先将数组排个序，然后开始遍历数组，思路跟那道三数之和很相似，都是先确定一个数，
然后用两个指针 left 和 right 来滑动寻找另外两个数，每确定两个数，我们求出此三数之和，
然后算和给定值的差的绝对值存在 newDiff 中，然后和 diff 比较并更新 diff 和结果 closest 即可
*/
class Solution1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3)
            return 0;
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if (diff > newDiff) {
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) ++left;
                else --right;
            }
        }
        return closest;
    }
};