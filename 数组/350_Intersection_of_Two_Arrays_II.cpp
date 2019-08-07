/*
Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //O(nlogn)
        map<int, int> record;
        for(int i = 0; i < nums1.size(); ++i){
            /*
            if(record.find(nums1[i]) == record.end()){
                record.insert(make_pair(nums1[i], 1));
            }
            else{
                ++record[nums1[i]];
            }
            */
            ++record[nums1[i]];
        }

        //O(nlogn)
        vector<int> result;
        for(int i = 0; i < nums2.size(); ++i){
            if(record[nums2[i]] > 0){
                result.push_back(nums2[i]);
                record[nums2[i]]--;
            }
            /*由于map的默认值为0，当访问键后会创建这个键，对应的值默认为0
            键对应的值为0和键不存在不是一回事
            if(record.find(nums2[i]) != record.end() && record[nums2[i]] > 0){
                result.push_back(nums2[i]);
                record[nums2[i]]--;
                if(record[nums2[i]] == 0){
                    record.erase(nums2[i]);
                }
            }
            */
        }
        return result;
    }
};

int main()
{
    return 0;
}