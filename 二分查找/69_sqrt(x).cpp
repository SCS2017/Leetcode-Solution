/*
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }
        int left = 0, right = x;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(x / mid >= mid){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return right - 1;
    }
    int mySqrt1(int x) {
        long long left = 1, right = x / 2 + 1;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            if(sq == x)
                return mid;
            else if(sq < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
    // 牛顿迭代法
    int mySqrt2(int x) {
        if (x == 0) return 0;
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return int(res);
        // long res = x;
        // while (res * res > x) {
        //     res = (res + x / res) / 2;
        // }
        // return res;
    }
};