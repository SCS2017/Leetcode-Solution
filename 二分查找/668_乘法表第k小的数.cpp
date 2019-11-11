/* 
几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？
给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。

例 1：
输入: m = 3, n = 3, k = 5
输出: 3
解释: 
乘法表:
1	2	3
2	4	6
3	6	9
第5小的数字是 3 (1, 2, 2, 3, 3).

例 2：
输入: m = 2, n = 3, k = 6
输出: 6
解释: 
乘法表:
1	2	3
2	4	6
第6小的数字是 6 (1, 2, 2, 3, 4, 6).

注意：
m 和 n 的范围在 [1, 30000] 之间。
k 的范围在 [1, m * n] 之间。
*/

#include <bits/stdc++.h>
using namespace std;

// 开始想用之前做的Leetcode378行列有序矩阵中第k小的数，但是由于m,n的范围很大，内存溢出
// 其实思路相同，还是二分查找
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        while(low < high){
            int mid = low + (high - low) / 2;
            int cnt = 0;
            // 由于乘法表的特殊性，每行均是1,2,...,m的1,2,...,n倍数
            // 这里在找矩阵中小于mid的数的个数时，直接使用min(n, mid / i)，i从1到m即可
            for(int i = 1; i <= m; ++i)
                cnt += min(n, mid / i);
            // 或者
            int i = m, j = 1;
            while(i >= 1 && j <= n){
                if(i * j <= mid){
                    cnt += i;
                    ++j;
                }
                else
                    --i;
            }
            if(cnt < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};

int main(){
    
    return 0;
}
