/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

说明 :
数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//二重循环，遍历所有的子列和
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            int tmpsum = 0;
            for(int j = i; j < nums.size(); ++j){
                tmpsum += nums[j];
                if(tmpsum == k){
                    res += 1;
                }
            }
        }
        return res;
    }
};

/*
使用哈希表来建立连续子数组之和跟其出现次数之间的映射，初始化要加入{0,1}这对映射
这样可以快速查找sum-k是否存在，也即是否有连续子数组的和为sum-k，这样，和为k的子数组也一定存在
遍历数组nums，计算从第0个元素到当前元素的和，用哈希表保存出现过的累积和sum的次数。
如果sum - k在哈希表中出现过，则代表从当前下标i往前有连续的子数组的和为sum。时间复杂度为O(n)，空间复杂度为O(1)。

*/
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            res += m[sum - k];
            ++m[sum];
        }
        for(auto item: m){
            cout << item.first << " " << item.second << endl;
        }
        return res;
    }
};

// 思路：记录从开始到位置i的累加和，再统计位置i之前有多少个累加和等于sum[i]-k.
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return 0;
        //计算到位置i的累加和
        vector<int> sum(n+1, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = nums[i-1] + sum[i-1];
        //查看在位置i之前，是否有sum[j]=sum[i]-k
        unordered_map<int,int> hash;
        hash[0] = 1;
        int res = 0;
        for (int i = 1; i <= n; i++){
            if (hash[sum[i]-k])
                res += hash[sum[i]-k];
            hash[sum[i]]++;
        }
        return res;
    }
};

int main()
{
    int n;
    while(cin >> n){
        vector<int> nums(n);
        for(int i = 0; i < nums.size(); ++i){
            cin >> nums[i];
        }
        int target;
        cin >> target;
        int res = Solution1().subarraySum(nums, target);
        cout << res << endl;
    }
    return 0;
}