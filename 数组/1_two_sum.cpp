#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
class Solution {
public:
    vector<int> static twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> d;
        vector<int> ret;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (d.find(nums[i]) == d.end())
            {
                d[target-nums[i]] = i;
            }
            else
            {
                ret.push_back(d[nums[i]]);
                ret.push_back(i);
                break;
            }
        }
        return ret;
    }
};
*/

//解法2

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i])) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};


int main()
{
    int n , target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    cout << "Input your target:" << endl;
    cin >> target;
    vector<int> res = Solution().twoSum(nums, target);
    for (vector<int>::iterator it = res.begin(); it < res.end(); it++) {
        cout << *it<<" ";
    }
    cout << endl;
    return 0;
}
