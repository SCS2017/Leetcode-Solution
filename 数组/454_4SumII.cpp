/*
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//将C+D的结果放入到查找表中O(n^2)，然后在遍历A和B
//另外一种思路是将A+B和C+D的结果分别放入两个查找表中O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> record;
        for(int i = 0; i < C.size(); ++i){
            for(int j = 0; j < D.size(); ++j){
                ++record[C[i] + D[j]];
            }
        }
        int res = 0;
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < B.size(); ++j){
                if(record.find(0 - A[i] - B[j]) != record.end()){
                    res += record[0 - A[i] - B[j]];
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}