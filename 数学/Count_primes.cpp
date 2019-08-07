/*
Count the number of prime numbers less than a non-negative number, n.
计算小于给定非负整数n的素数的个数

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int countPrimes(int n){
    if(n < 3){
        return 0;
    }
    vector<bool> nums(n, true);
    nums[0] = nums[1] = false;
    int res = 0;
    for(int i = 2; i <= sqrt(n); ++i){
        if(nums[i]){
            for(int j = i * i; j < n; j += i){
                nums[j] = false;
            }
        }
    }
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i]){
            ++res;
        }
    }
    return res;
}

int main()
{
    int n;
    while(cin >> n){
        int res = countPrimes(n);
        cout << res << endl;
    }
    return 0;
}