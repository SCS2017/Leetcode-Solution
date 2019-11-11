/* 
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <bits/stdc++.h>
using namespace std;

/* 
我们再来看下面一个例子，有如下的一个数组
1　　2　　7　　4　　3　　1
下一个排列为：
1　　3　　1　　2　　4　　7

那么是如何得到的呢，我们通过观察原数组可以发现，如果从末尾往前看，数字逐渐变大，到了2时才减小的，
然后我们再从后往前找第一个比2大的数字，是3，那么我们交换2和3，再把此时3后面的所有数字转置一下即可，步骤如下：
1　　2　　7　　4　　3　　1
1　　2　　7　　4　　3　　1
1　　3　　7　　4　　2　　1
1　　3　　1　　2　　4　　7
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j, n = nums.size();
        for(i = n-2; i >= 0; --i){
            if(nums[i+1] > nums[i]){
                for(j = n-1; j > i; --j){
                    if(nums[j] > nums[i])
                        break;      
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

// my solution
class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
        int j = nums.size()-1;
        while(j > 0 && nums[j] <= nums[j-1])
            --j;
        if(j == 0)
            reverse(nums.begin(), nums.end());
        else{
            int i = nums.size()-1;
            for(; i >= j; --i){
                if(nums[i] > nums[j-1])
                    break;
            }
            swap(nums[i], nums[j-1]);
            reverse(nums.begin()+j, nums.end());
        }
    }
};
