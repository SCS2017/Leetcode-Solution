/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //维护一个长度为k的无序集合，一旦长度超过k，就把nums[i-k]去掉
        unordered_set<int> record;
        for(int i = 0; i < nums.size(); ++i){
            if(record.find(nums[i]) != record.end()){
                return true;
            }
            record.insert(nums[i]);
            if(record.size() == k + 1){
                record.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}