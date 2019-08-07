/*
计算数组中每个数右边比它小的数的个数，返回值也为数组
Example:
Input: [5,2,6,1]
Output: [2,1,1,0] 

Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countSmall(vector<int>& nums)
{
    int length = nums.size();
    vector<int>result(length, 0);
    if(length == 0){
        return result;
    }
    int count = 0;
    for(int i = 0; i < nums.size() - 1; i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if(nums[j] < nums[i])
            {
                count++;
            }
        }
        result[i] = count;
        count = 0;
    }
    return result;
}

/*
先对数组排序，得到排序后的数组，接下来遍历原来的数组，找到其在排序后数组中的位置，即为其逆序数，
然后在排序后的数组中删除这个元素。重复这个过程
很简单的想法，也通过了，不过时间有点长
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int cnt = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for(auto a: nums){
            int num = distance(sorted.begin(), find(sorted.begin(), sorted.end(), a));
            res.push_back(num);
            sorted.erase(sorted.begin()+num);
        }
        return res;
    }
};

/* 
首先可以使用用二分搜索法，思路是将给定数组从最后一个开始，用二分法插入到一个新的数组，这样新数组就是有序的，
那么此时该数字在新数组中的坐标就是原数组中其右边所有较小数字的个数，
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> result, result1;
    for(int i=0; i<arr.size(); ++i)
        cin >> arr[i];
    result1 = Solution().countSmaller(arr);
    for(vector<int>::iterator it=result1.begin(); it < result1.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}