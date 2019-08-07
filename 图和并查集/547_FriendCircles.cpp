/*
班上有N名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知A是B的朋友，B是C的朋友，那么我们可以认为A也是C的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个N*N的矩阵M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第i个和j个学生互为朋友关系，否则为不知道。
你必须输出所有学生中的已知的朋友圈总数。

示例 1:
输入: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。

示例 2:
输入: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。

注意：
N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。
*/

#include <bits/stdc++.h>

using namespace std;

//直接的解法就是DFS搜索，对于某个人，遍历其好友，然后再遍历其好友的好友，那么我们就能把属于同一个朋友圈的人都遍历一遍，
//我们同时标记出已经遍历过的人，然后累积朋友圈的个数，再去对于没有遍历到的人在找其朋友圈的人，这样就能求出个数。
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < M.size(); ++i){
            if(visited[i])
                continue;
            help(M, i, visited);
            ++res;
        }
        return res;
    }
    void help(vector<vector<int>>& M, int k, vector<bool>& visited){
        visited[k] = true;
        for(int i = 0; i < M.size(); ++i){
            if(!M[k][i] || visited[i])
                continue;
            help(M, i, visited);
        }
    }
};


//使用并查集
struct UF{
    UF(int n){
        nums.resize(n);
        for(int i = 0; i < n; ++i)
            nums[i] = i;
        //确定合并后的数目
        stuNum = n;
    }
    int find(int k){
        if(k != nums[k])
            nums[k] = find(nums[k]);
        return nums[k];
    }
    bool unionElement(int a, int b){
        int aRoot = find(a), bRoot = find(b);
        if(aRoot == bRoot)
            return false;
        nums[bRoot] = aRoot;
        --stuNum;
        return true;
    }
    vector<int> nums;
    int stuNum;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UF friends(M.size());
        for(int i = 0; i < M.size(); ++i){
            for(int j = 0; j < M[i].size(); ++j){
                if(M[i][j] == 1)
                    friends.unionElement(i, j);
            }
        }
        return friends.stuNum;
    }
};

int main(){
    
    return 0;
}
