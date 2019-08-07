/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:
输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:
输入: [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:
输入: [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

//动态规划
//按照区间开始排序
//排序函数要在类外定义
bool cmp(const Interval &a, const Interval &b){
    if(a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        //memo[i]表示使用intervals[0...i]的区间构成的最长不重叠区间序列
        vector<int> memo(intervals.size(), 1);
        for(int i = 1; i < intervals.size(); ++i){
            for(int j = 0; j < i; ++i){
                if(intervals[i].start >= intervals[j].end){
                    memo[i] = max(memo[i], 1 + memo[j]);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < memo.size(); ++i){
            res = max(res, memo[i]);
        }
        return intervals.size() - res;
    }
};

/*
注意：每次选择中，每个区间的结尾很重要
结尾越小，留给后面的空间越大
*/

/*
贪心算法
按照区间结尾排序，每次选择结尾最早的，且和前一个区间不重叠的区间
*/

//如果无法使用贪心算法，举出反例即可
//如果无法举出反例，如何证明贪心算法的正确性？
bool cmp1(const Interval &a, const Interval &b){
    if(a.end != b.end)
        return a.end < b.end;
    return a.start < b.start;
}

class Solution1 {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp1);
        int res = 1;
        int pre = 0;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i].start >= intervals[pre].end){
                ++res;
                pre = i;
            }
        }
        return intervals.size() - res;
    }
};