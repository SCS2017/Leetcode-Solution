
/*
非空整数数组中，所有数都出现两次，只有一个数出现一次，找出这个数
Example 1:
Input: [2,2,1]
Output: 1

Example 2:
Input: [4,1,2,1,2]
Output: 4
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            res ^= nums[i];
        }
        return res;
    }
};