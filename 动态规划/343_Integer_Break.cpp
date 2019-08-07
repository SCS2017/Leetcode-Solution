/*
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。

示例 2:
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;
    //将n进行分割(至少分割两部分)，可以获得的最大乘积
    int help(int n) {
        if( n == 1){
            return 1;
        }
        if(memo[n] != -1){
            return memo[n];
        }
        int res = -1;
        
        for(int i = 1; i <= n - 1; ++i){
            //这里可以对n-i继续分割或者是不分割
            res = max(res, max(i * (n - i), i * help(n - i)));
        }
        memo[n] = res;
        return res;
    }
public:
    int integerBreak(int n){
        memo = vector<int>(n + 1, -1);
        return help(n);
    }
};

class Solution1{
public:
    int integerBreak(int n){
        //memo[i]表示将数字i分割(至少分割两部分)后得到的最大乘积
        vector<int> memo(n + 1, -1);
        memo[1] = 1;
        for(int i = 2; i <= n; ++i){
            //求解memo[i]
            for(int j = 1; j <= i - 1; ++j){
                //j + (i - j)
                memo[i] = max(memo[i], max(j * (i - j), j * memo[i - j]));
            }
        }
        return memo[n];
    }
};

int main()
{
    int n;
    while(cin >> n){
        int res = Solution1().integerBreak(n);
        cout << res << endl;
    }
    return 0;
}