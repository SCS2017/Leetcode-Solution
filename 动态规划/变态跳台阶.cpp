#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int climbStairs(int n){
        int p[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
        vector<long long> dp(1001, 0);
        dp[0] = 1;
        for(int i = 1; i <= 1000; ++i){
            for(int j = 0; j < 10 && i >= p[j]; ++j){
                dp[i] += dp[i - p[j]];
                dp[i] %= 1000000003LL;
            }
        }
        return dp[n];
    }
};

int main()
{
    int n;
    while(cin >> n){
        vector<int> nums(n);
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        vector<int> res;
        for(int i = 0; i < n; ++i){
            int tmp = Solution().climbStairs(nums[i]);
            res.push_back(tmp);
        }
        for(int i = 0; i < res.size(); ++i){
            cout << res[i] << endl;
        }
    }
    return 0;
}