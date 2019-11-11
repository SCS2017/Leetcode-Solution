/* 
计算小于非负数n的质数的个数。
 
样例
样例 1
输入: n = 2
输出: 0

样例 2
输入: n = 4
输出: 2
解析：2, 3 是素数
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */
    int countPrimes(int n) {
        // write your code here
        if(n < 3)
            return 0;
        vector<int> flag(n, 1);
        flag[0] = 0,
        flag[1] = 0;
        for(int i = 2; i < sqrt(n)+1; ++i){
            if(flag[i] == 1){
                for(int j = i*i; j < n; j += i)
                    flag[j] = 0;
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i)
            res += flag[i];
        return res;
    }
};

int main(){
    
    return 0;
}
