/*
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，
k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例
输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

就是按照k来排序，满足排在某个元素的前面有k个人的身高大于等于h
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        //[[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
        vector<vector<int>> res;
        for(auto tmp: people)
            res.insert(res.begin()+tmp[1], tmp);
        return res;
    }
    //先按照身高h降序排列，在按照k升序排列，然后根据k插入相应位置
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
};

int main(){
    
    return 0;
}
