/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
一个数可以使用多次
图是什么
  节点：x(当前的和，当前要考虑的数a[i])
  边：x->
       y1(当前的和，下一个要考虑的数a[i + 1])
       y2(当前的和+a[i]，下一个要考虑的数a[i + 1])
*/

//DFS
class Solution {
public:
    //now为下标，sum为当前和
    void help(vector<int>& a, int now, int sum, int target, vector<int>& path, vector<vector<int>>& answer){
        //当前值大于target，直接返回
        if(sum > target){
            return;
        }
        //所有的数都考虑过
        if(now >= a.size()){
            if(sum == target){
                answer.push_back(path);
            }
            return;
        }
        if((now == 0) || (a[now - 1] != a[now])){
            path.push_back(a[now]);
            help(a, now, sum + a[now], target, path, answer);
            path.pop_back();
        }
        help(a, now + 1, sum, target, path, answer);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> answer;
        help(candidates, 0, 0, target, path, answer);
        return answer;
    }
};

/*
写一个递归函数，这里我们新加入三个变量，start记录当前的递归到的下标，out为一个解，res保存所有已经得到的解，
每次调用新的递归函数时，此时的target要减去当前数组的的数
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, target, 0, path, res);
        return res;
    }
private:
    void dfs(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& res){
        if(target < 0)
            return;
        if(target == 0){
            res.push_back(path);
            return;
        }
        for(int i = start; i < candidates.size(); ++i){
            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, path, res);
            path.pop_back();
        }
    }
};

int main()
{
    return 0;
}
