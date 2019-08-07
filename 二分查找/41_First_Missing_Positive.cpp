/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:
输入: [1,2,0]
输出: 3

示例 2:
输入: [3,4,-1,1]
输出: 2

示例 3:
输入: [7,8,9,11,12]
输出: 1

说明:
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
const int INT_MIN = -1000000;

/*
使用unordered_set结构的集合st装入nums中的元素，同时找到nums元素的最大值Max，然后遍历1~Max范围内的数，
找到第一个不在集合st中数就是缺失的第一个正数，如果都在集合st中，那么缺失的第一个正数就在1和Max+1的较大值中取得。

时间复杂度：O(n) 空间复杂度：O(n)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        int maxnum = INT_MIN;
        for(auto num: nums){
            s.insert(num);
            maxnum = max(maxnum, num);
        }
        for(int i = 1; i <= maxnum; ++i){
            if(s.count(i) == 0)
                return i;
        }
        return max(maxnum + 1, 1);
    }
};

/*
对于大小为n（n>0）的数组，这n个数可以分为以下几种情况：
这n个数都小于等于0
这n个数都大于n
存在一个或多个位于[1,n]的数

对于情况1和情况2，要查找的第一个缺失的正数就是1；

问题是对于情况3应该怎么考虑呢？
假设这些位于[1,n]的数i，在数组中的位置应该为i-1，而小于等于0的数，以及大于n的数，在数组剩余位置：
如果数组所有的数都在[1,n]，那么每个元素都在其值减1的位置，此时要找的第一个缺失的整数就是n+1；
否则，数组中，必然存在一个位置idx，其元素值不等于idx+1，而范围[1,n]就是正数序列最开始的n个数，
因此，从左往右查找第一个下标加1不等于值的位置，那么要找的第一个缺失的正数就是该位置的下标加1。
注意：交换元素的方法可以将范围在[1,n]的元素放置到正确的位置,

时间复杂度：O(n) 空间复杂度：O(1)
*/
class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 1;
        //交换元素的方法可以将范围在[1,n]的元素放置到正确的位置
        for(int i = 0; i < len; ++i){
            while(nums[i] > 0 && nums[i] <= len && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // for(int i = 0; i < len; ++i)
        //     cout << nums[i] << " ";
        // cout << endl;
        for(int i = 0; i < len; ++i){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return len + 1;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    int res = Solution1().firstMissingPositive(nums);
    cout << res << endl;
    return 0;
}