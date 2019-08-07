/*
四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        if(nums.size() < 4){
            return vector<vector<int>>(res.begin(), res.end());
        }
        sort(nums.begin(), nums.end());
        //nums.size()是unsigned int，当nums.size()为0时，nums.size()-2就为2^32-2，循环次数就炸了
        for(int i = 0; i < int(nums.size() - 3); ++i){
            for(int j = i + 1; j < int(nums.size() - 2); ++j){
                if((j > i + 1) && (nums[j] == nums[j-1])) continue;
                int left = j + 1, right = nums.size() - 1;
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left;
                        --right;
                    }
                    else if(sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

int main()
{
    int n;
    cout << "input the length of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "input an array: ";
    for(int i = 0; i < arr.size(); ++i){
        cin >> arr[i];
    }
    int target;
    cout << "input a target: ";
    cin >> target;
    Solution first;
    vector<vector<int> > res;
    res = first.fourSum(arr, target);
    vector<int> tmp;
    cout << "result is:" << endl;
    for(vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it){
        tmp = *it;
        for(vector<int>::iterator itt = tmp.begin(); itt != tmp.end(); ++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
    return 0;
}