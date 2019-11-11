/* 

*/

#include <bits/stdc++.h>
using namespace std;

// 时间O(n)，空间O(1)
// 还是与找到重复数相同的思想
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
                --i;
            }
        }
        for(int j = 0; j < nums.size(); ++j){
            if(nums[j] != j+1){
                res.push_back(j+1);
            }
        }
        return res;
    }
};


// 时间O(n)，空间O(n)
class Solution1 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> flag(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i){
            flag[nums[i]] = 1;
        }
        for(int j = 1; j < flag.size(); ++j){
            if(flag[j] == 0){
                res.push_back(j);
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}
