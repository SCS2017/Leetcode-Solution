/*
有一个研究员的论文的引用数组，写一个函数计算研究员的h指数。

h指数是指：N篇论文中有h篇至少有h次引用，其他N-h篇论文不超过（小于等于）h次引用（取满足条件的最大的h值）。

思路：
1、先排序，判断如果有数字满足citations[i] >= len-i 则它满足条件。意思是至少有len-i篇论文引用次数不低于len-i。

比如1,2,3,4,5,6，则结果是3，至少有3篇论文引用次数大于等于3，其他3篇论文引用次数小于等于3.

2、O(n)的解法。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int len = citations.size();
        for(int i = 0; i < len; ++i){
            //注意这里的返回值一定是len - i，而不是citations[i]
            //因为题目中是至少有h篇论文引用次数 大于等于 h
            //是大于等于，可以大于，这里给的例子是等于
            if(citations[i] >= len - i){
                return len - i;
            }
        }
        return 0;
    }
};

int main()
{
    int arr[] = {3, 0, 6, 1, 5};
    int len = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + len);
    int res = Solution().hIndex(nums);
    cout << res << endl;
    return 0;
}
