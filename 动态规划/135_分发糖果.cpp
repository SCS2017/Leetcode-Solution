/* 
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:
输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。

示例 2:
输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
*/

#include <bits/stdc++.h>
using namespace std;

/* 
首先初始化每个人一个糖果，然后这个算法需要遍历两遍，第一遍从左向右遍历，如果右边的小盆友的等级高，等加一个糖果，
这样保证了一个方向上高等级的糖果多。然后再从右向左遍历一遍，如果相邻两个左边的等级高，而左边的糖果又少的话，
则左边糖果数为右边糖果数加一。最后再把所有小盆友的糖果数都加起来返回即可。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty())
            return 0;
        int n = ratings.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1])
                dp[i] = dp[i-1] + 1;
        }
        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1])
                dp[i] = max(dp[i], dp[i+1]+1);
        }
        int res = 0;
        for(auto tmp: dp)
            res += tmp;
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    int res = Solution().candy(nums);
    cout << res << endl;
    return 0;
}
