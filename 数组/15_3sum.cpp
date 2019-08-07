/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[right] == target){
                    vector<int> out{nums[i], nums[left], nums[right]};
                    res.insert(out);
                    while(left < right && nums[left] == nums[left + 1]) ++left;
                    while(left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                }
                else if(nums[left] + nums[right] < target) ++left;
                else --right;
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < nums.size(); ++i){
        cin >> nums[i];
    }
    cout << "The result is: " << endl;
    vector<vector<int>> res;
    Solution first;
    res = first.threeSum(nums);
    for(vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it){
        vector<int> tmp = *it;
        for(vector<int>::iterator itt = tmp.begin(); itt != tmp.end(); ++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
    return 0;
}