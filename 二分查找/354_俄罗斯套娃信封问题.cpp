/* 
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。
当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:
输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
*/

#include <bits/stdc++.h>
using namespace std;

/* 
首先来看DP的解法，这是一种brute force的解法，首先要给所有的信封按从小到大排序，首先根据宽度从小到大排，如果宽度相同，
那么高度小的再前面，这是STL里面sort的默认排法，所以我们不用写其他的comparator，直接排就可以了，然后我们开始遍历，
对于每一个信封，我们都遍历其前面所有的信封，如果当前信封的长和宽都比前面那个信封的大，那么我们更新dp数组，
通过dp[i] = max(dp[i], dp[j] + 1)。然后我们每遍历完一个信封，都更新一下结果res
*/

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        int res = 0, n = envelopes.size();
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

/* 
我们还可以使用二分查找法来优化速度，我们首先要做的还是给信封排序，但是这次排序和上面有些不同，信封的宽度还是从小到大排，
但是宽度相等时，我们让高度大的在前面。
*/

class Solution1 {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        for (int i = 0; i < envelopes.size(); ++i) {
            int left = 0, right = dp.size(), t= envelopes[i].second;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < t) left = mid + 1;
                else right = mid;
            }
            if (right >= dp.size()) dp.push_back(t);
            else dp[right] = t;
        }
        return dp.size();
    }
};

// 既然可以用二分查找法，那么使用STL的自带函数lower_bound也没啥问题了
class Solution2 {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end()) dp.push_back(envelopes[i].second);
            else *it = envelopes[i].second;
        }
        return dp.size();
    }
};
