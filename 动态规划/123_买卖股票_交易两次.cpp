/* 

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
dp1[i] = max(dp[i-1], prices[i] - minval) 从前往后遍历，表示第1天到第i天之间的最大利润（通过是否在第i天卖出确认）；
dp2[i] = max(dp[i+1], maxval - prices[i]) 从后往前遍历，表示第i天到最后一天之间的最大利润（通过是否在第i天买进确认）；
res = max(dp1 + dp2)，(dp1 + dp2)[i] 正好表示从第1天到最后一天经过两次交易的最大利润，我们的目标是找到令总利润最大的i。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        vector<int> left(n, 0), right(n, 0);
        int minval = prices[0];
        for(int i = 1; i < n; ++i){
            left[i] = max(left[i-1], prices[i] - minval);
            minval = min(minval, prices[i]);
        }
        int maxval = prices.back();
        for(int i = n-2; i >= 0; --i){
            right[i] = max(right[i+1], maxval - prices[i]);
            maxval = max(maxval, prices[i]);
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};