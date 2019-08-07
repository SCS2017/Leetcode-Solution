/*
给定N个整数的序列，求其子序列的最大和

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include <iostream>
#include <vector>
#include <climits>  
//内置类型的宏定义，包括INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, CHAR_MIN, CHAR_MAX等等

using namespace std;

int MaxSubseqSum(vector<int>& arr)
{
    int ThisSum = 0;
    int MaxSum = INT_MIN;
    for(vector<int>::iterator it=arr.begin(); it !=arr.end(); it++)
    {
        if(ThisSum < 0){
            ThisSum = 0;        //如果当前子列和为负数，舍弃
        }
        ThisSum += *it;    //向右累加
        MaxSum = max(ThisSum, MaxSum);
    }
    return MaxSum;
}

/*动态规划  递推式、初值、空间优化
dp[i]表示以a[i]结尾的最大子数组的和
dp[i] = max(dp[i-1] + a[i], a[i])
初值dp[0] = a[0]
答案是最大的dp[0....n-1]
时间和空间复杂度均为O(n)
空间优化：dp[i]要存吗？
ThisSum = max(ThisSum + nums[i], nums[i])
结果MaxSum = max(MaxSum, ThisSum)
*/
int maxSubArray1(vector<int>& nums) {
    int ThisSum = 0;
    int MaxSum = INT_MIN;
    for(int i = 0; i < nums.size(); ++i){
        ThisSum = max(ThisSum + nums[i], nums[i]);
        MaxSum = max(MaxSum, ThisSum);
    }
    return MaxSum;
}

/*分治
分：两个基本等长的子数组，分别求解T(n/2)
合：跨越中心点的最大子数组合（枚举）O(n)
时间复杂度O(nlogn)
*/
int maxSubArray2(int A[], int n)
{
    if(n == 1){
        return A[0];
    }
    int mid = n >> 1;
    int answer = max(maxSubArray2(A, mid), maxSubArray2(A+mid, n-mid));
    int now = A[mid-1], may = now;
    for(int i = mid - 2; i >= 0; --i){
        may = max(may, now += A[i]);
    }
    now = may;
    for(int i = mid; i < n; ++i){
        may = max(may, now += A[i]);
    }
    return max(answer, may);
}

int main()
{
    int result;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<arr.size(); ++i)
    {
        cin >> arr[i];
    }
    result = MaxSubseqSum(arr);
    cout << result << endl;
    return 0;
}