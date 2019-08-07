/*
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            /*
            判断key=nums[i]是否存在
            如果key存在，则find返回key对应的迭代器，如果key不存在，则find返回unordered_map::end。因此可以通过
            map.find(key) == map.end()来判断，key是否存在于当前的unordered_map中。
            */
            if(m.find(nums[i]) != m.end()){
                return true;
            }
            ++m[nums[i]];
        }
        return false;
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
    Solution first;
    bool res;
    res = first.containsDuplicate(nums);
    cout << boolalpha << res << endl;
    return 0;
}