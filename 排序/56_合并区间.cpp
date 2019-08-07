/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

*/

#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval& l1, const Interval& l2){
    if(l1.start == l2.start)
        return l1.end < l2.end;
    return l1.start < l2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        if(len <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < len; ++i){
            int tail = res.back().end;
            if(intervals[i].start <= tail){
                res.back().end = max(tail, intervals[i].end);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

int main(){

    return 0;
}