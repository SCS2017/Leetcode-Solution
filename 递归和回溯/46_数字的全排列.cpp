/*
LeetCode 46: permutations
例题说明：给出一组互不相同的数字形成的集合，返回所有的排列组合。

例： 
输入： [1, 2, 3] 
输出：

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//树形问题
/*
主要的思路是遍历输入集合，抽取当前数组其中一个元素，此时将集合分为两部分：抽取元素，以及剩余元素组成的子集合。
对子集合不断进行递归操作，最后将先前抽取的元素放置在每次递归返回的结果尾部。

具体的实现思路如下：
设立递归的返回条件：输入集合元素数量小于等于 1，则立即返回；
遍历输入集合所有元素： 
将集合分为两部分：挑选集合中任一个元素，以及剩余元素组成的子集；
对子集进行递归，返回一个集合；
将先前挑出来的元素放置在递归后返回的集合中；
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int> > permute(vector<int>& nums){
        vector<vector<int> > res, dst;
        if(nums.size() == 1){
            dst.push_back(nums);
            return dst;
        }
        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            vector<int> set = nums;
            set.erase(set.begin() + i);

            res = permute(set);

            for(int j = 0; j < res.size(); ++j){
                vector<int> tmp = res[j];
                tmp.push_back(num);
                dst.push_back(tmp);
            }
        }
        return dst;
    }
};

class Solution1{
public:
    vector<vector<int> > permute(vector<int>& nums){
        if(nums.size() == 0){
            return res;
        }
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<bool> used;
    //p中保存了一个有index个元素的排列
    //向这个排列的末尾添加第index+1个元素，获得一个有index+1个元素的排列
    void generatePermutation(const vector<int>& nums, int index, vector<int>& p){
        if(index == nums.size()){
            res.push_back(p);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!used[i]){
                //将nums[i]添加在p中
                p.push_back(nums[i]);
                // for(vector<int>::iterator it = p.begin(); it != p.end(); ++it){
                //     cout << *it << " ";
                // }
                // cout << endl;
                used[i] = true;
                generatePermutation(nums, index + 1, p);
                p.pop_back();
                // for(vector<int>::iterator it = p.begin(); it != p.end(); ++it){
                //     cout << *it << " ";
                // }
                // cout << endl;
                used[i] = false;
            }
        }
        return;
    }
};

class Solution2 {
public:
    vector<vector<int> > permute(vector<int>& nums){
        if(nums.size() == 0){
            return res;
        }
        help(nums, 0);
        return res;
    }
    void help(vector<int>& nums, int start){
        if (start == nums.size()){
            res.push_back(nums);
            return;
        }
 
        for (int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            help(nums, start+1);
            swap(nums[start], nums[i]);
        }
    }
private:
    vector<vector<int> > res;
};

// 使用STL中的next_permutation函数，但是必须先对数组排序，否则结果不对
class Solution3 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())){
            res.push_back(nums);
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
    Solution2 first;
    result = first.permute(arr);
    for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it){
        vector<int> tmp = *it;
        for(vector<int>::iterator itt = tmp.begin(); itt != tmp.end(); ++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
    return 0;
}