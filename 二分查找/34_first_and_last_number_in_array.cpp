/*
'''
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
'''
#要求时间复杂度为O(log n)

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1,-1};
        if(nums[0] <= target && nums.back() >= target){
            int left = 0, right = nums.size()-1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target){
                    left = mid;
                    right = mid;
                    while((left - 1 >= 0) && nums[left-1] == target)
                        --left;
                    while((right+1 < nums.size()) && nums[right+1] == target)
                        ++right;
                    return {left, right};
                }
                else if(nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return {-1, -1};
    }
};

int main()
{
    int n, target;
    cin >> n;
    vector<int> arr(n);
    vector<int> result;
    for(int i=0; i<arr.size(); i++){
        cin >> arr[i];
    }
    cout << "Input your target:" << endl;  //endl表示换行
    cin >> target;
    result = Solution().searchRange(arr, target);
    for(vector<int>::iterator it=result.begin();it<result.end();it++){
        cout << *it << " ";  
    }
    cout << endl;
    return 0;
}