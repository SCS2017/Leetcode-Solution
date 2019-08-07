/*
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:
Each element in the result must be unique.
The result can be in any order.
*/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        //O(nlogn) set和map的底层实现是平衡二叉搜索树O(logn)
        set<int> record(nums1.begin(), nums1.end());

        //O(n) unordered_set和unordered_map的底层实现是哈希表O(1)
        //unordered_set<int> record(nums1.begin(), nums1.end());
        
        //O(nlogn)
        set<int> resSet;
        for(int i = 0; i < nums2.size(); ++i){
            if(record.find(nums2[i]) != record.end()){
                resSet.insert(nums2[i]);
            }
        }
        //O(n)
        return vector<int>(resSet.begin(), resSet.end());
    }
};

int main()
{
    return 0;
}