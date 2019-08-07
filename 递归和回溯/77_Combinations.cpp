/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// 当前为1：[2, 3, 4]中选一个
// 当前为2：[3, 4]中选一个
// 当前为3：[4]
// 当前为4：[]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0 || k > n){
            return res;
        }
        vector<int> c;
        getCombination(n, k, 1, c);
        return res;
    }
private:
    //求解组合数C(n, k)，当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    vector<vector<int>> res;
    void getCombination(int n, int k, int start, vector<int>& c){
        if(c.size() == k){
            res.push_back(c);
            return;
        }
        for(int i = start; i <= n; ++i){
            c.push_back(i);
            getCombination(n, k, i + 1, c);
            c.pop_back();
        }
        return;
    }
};

//优化-> 回溯法的剪枝
//可以不用再去处理4
class Solution1 {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0 || k > n){
            return res;
        }
        vector<int> c;
        getCombination(n, k, 1, c);
        return res;
    }
private:
    //求解组合数C(n, k)，当前已经找到的组合存储在c中，需要从start开始搜索新的元素
    vector<vector<int>> res;
    void getCombination(int n, int k, int start, vector<int>& c){
        if(c.size() == k){
            res.push_back(c);
            return;
        }
        //还有k - c.size()个空位，所有，[i....n]中至少要有k-c.size()个元素
        //i最多为n - (k - c.size()) + 1
        for(int i = start; i <= n - (k - c.size()) + 1; ++i){
            c.push_back(i);
            getCombination(n, k, i + 1, c);
            c.pop_back();
        }
        return;
    }
};