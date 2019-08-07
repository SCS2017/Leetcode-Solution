/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

/*
递归的解法，相当于一种深度优先搜索，参见网友JustDoIt的博客，由于原集合每一个数字只有两种状态，
要么存在，要么不存在，那么在构造子集时就有选择和不选择两种情况，所以可以构造一棵二叉树，
左子树表示选择该层处理的节点，右子树表示不选择，最终的叶节点就是所有子集合，
树的结构如下：
                        []        
                   /          \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 3] [1 2] [1 3] [1] [2 3] [2] [3] []    
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, tmp, res);
        return res;
    }
    void dfs(vector<int>& nums, int index, vector<int>& tmp, vector<vector<int> >& res){
        res.push_back(tmp);
        for(int i = index; i < nums.size(); ++i){
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
};

/*
非递归解法
对于题目中给的例子[1,2,3]来说，最开始是空集，那么我们现在要处理1，就在空集上加1，为[1]，现在我们有两个子集[]和[1]，
下面我们来处理2，我们在之前的子集基础上，每个都加个2，可以分别得到[2]，[1, 2]，那么现在所有的子集合为
[], [1], [2], [1, 2]，同理处理3的情况可得[3], [1, 3], [2, 3], [1, 2, 3], 再加上之前的子集就是所有的子集合了
*/
class Solution1{
public:
    vector<vector<int> > subsets(vector<int>& nums){
        vector<vector<int> > res(1);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int s = res.size();
            for(int j = 0; j < s; ++j){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < arr.size(); ++i){
        cin >> arr[i];
    }
    vector<vector<int> > result;
    Solution first;
    result = first.subsets(arr);
    for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it){
        vector<int> tmp = *it;
        for(vector<int>::iterator itt = tmp.begin(); itt != tmp.end(); ++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
    return 0;
}