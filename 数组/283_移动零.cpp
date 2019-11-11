/* 
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty())
            return;
        int i = 0, tail = -1;
        while(i < nums.size()){
            if(nums[i] != 0){
                swap(nums[i++], nums[++tail]);
            }
            else
                ++i;
        }
    }
};

// 需要用两个指针，一个不停的向后扫，找到非零位置，然后和前面那个指针交换位置即可
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                swap(nums[i], nums[j++]);
            }
        }
    }
};

int main(){
    
    return 0;
}
