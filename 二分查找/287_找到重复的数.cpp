/*
找出重复的整数，数组长度为n+1，且每个整数都在[1, n]之间，其中只有一个重复的数。
要求时间复杂度小于O(n^2)，空间复杂度为O(1)

Example 1:
Input: [1,3,4,2,2]
Output: 2

Example 2:
Input: [3,1,3,4,2]
Output: 3
*/

/*
二分法，每个整数都在[1, n]之间，left=1, right=n，
比较数组中小于mid = (left+right)/2的个数，如果大于mid，
则出现的重复值位于[left, mid], 否则在[mid, right]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        //循环终止条件为left=right
        while(left < right){
            int mid = left + (right - left) >> 1;
            //统计数组中小于等于mid的元素的个数
            int number = 0;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] <= mid){
                    ++number;
                }
            }
            if(number > mid){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution first;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
    int result;
    result = first.findDuplicate(arr);
    cout << result << endl;
    return 0;
}