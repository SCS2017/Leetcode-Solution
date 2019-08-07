/*
给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，
其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/

#include <iostream>
#include <vector>

using namespace std;

/*
由于output[i] = (x[0] * x[1] * ... * x[i-1]) * (x[i+1] * .... * x[n-1])

因此执行两趟循环：

第一趟正向遍历数组，计算x[0] ~ x[i-1]的乘积

第二趟反向遍历数组，计算x[i+1] ~ x[n-1]的乘积
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1), res(n);
        for(int i = 0; i < n - 1; ++i){
            left[i + 1] = left[i] * nums[i];
        }
        for(int j = n - 1; j > 0; --j){
            right[j - 1] = right[j] * nums[j]; 
        }
        for(int i = 0; i < n; ++i){
            res[i] = left[i] * right[i];
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
        Solution fir;
        vector<int> res = fir.productExceptSelf(nums);
        for(vector<int>::iterator it = res.begin(); it != res.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}