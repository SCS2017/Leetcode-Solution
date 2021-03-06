/* 
如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：
n >= 3
对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}
给定一个严格递增的正整数数组形成序列，找到 A 中最长的斐波那契式的子序列的长度。如果一个不存在，返回 0 。

子序列是从原序列 A 中派生出来的，它从 A 中删掉任意数量的元素（也可以不删），而不改变其余元素的顺序。
例如， [3, 5, 8] 是 [3, 4, 5, 6, 7, 8] 的一个子序列

示例 1：
输入: [1,2,3,4,5,6,7,8]
输出: 5
解释:
最长的斐波那契式子序列为：[1,2,3,5,8] 。

示例 2：
输入: [1,3,7,11,12,14,18]
输出: 3
解释:
最长的斐波那契式子序列有：
[1,11,12]，[3,11,14] 以及 [7,11,18] 。
 
提示：
3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
（对于以 Java，C，C++，以及 C# 的提交，时间限制被减少了 50%）
*/

#include <bits/stdc++.h>
using namespace std;


// 暴力解法O，有点问题
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        if(n < 3)
            return 0;
        // vector<int> dp(n, 1);
        int res = 0;
        for(int i = 0; i < n-2; ++i){
            for(int j = i+1; j < n-1; ++j){
                int cnt = 2;
                for(int k = j+1; k < n; ++k){
                    int left = i, right = j;
                    while(A[left] + A[right] == A[k]){
                        ++cnt;
                        left = j;
                        right = k;
                        ++k;
                    }
                }
                res = max(res, cnt);
            }
        }
        if(res < 3)
            return 0;
        return res;
    }
};

// hashset空间换时间
class Solution1 {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size(), res = 0;
        unordered_set<int> st(A.begin(), A.end());
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int cnt = 2, a = A[i], b = A[j];
                while(st.count(a+b)){
                    ++cnt;
                    b = a + b;
                    a = b - a;
                }
                res = max(res, cnt);
            }
        }
        return (res > 2) ? res : 0;
    }
};

int main(){
    int num;
    vector<int> nums;
    while(cin >> num){
        nums.push_back(num);
        if(cin.get() == '\n')
            break;
    }
    int cnt = Solution().lenLongestFibSubseq(nums);
    cout << cnt << endl;
    return 0;
}
