/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
返回 13。

说明: 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n^2 。
*/

#include <bits/stdc++.h>
using namespace std;

//使用最大优先队列，遍历整个数组，得到最小的k个数，然后返回top元素即可
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>> pq;
        int m = matrix.size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < m; ++j){
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                    pq.pop();
                // if(pq.size() < k)
                //     pq.push(matrix[i][j]);
                // else{
                //     if(matrix[i][j] < pq.top()){
                //         pq.pop();
                //         pq.push(matrix[i][j]);
                //     }
                // }
            }
        }
        return pq.top();
    }
};


/* 
二分查找法来做，我们由于是有序矩阵，那么左上角的数字一定是最小的，而右下角的数字一定是最大的，所以这个是我们搜索的范围，
然后我们算出中间数字mid，由于矩阵中不同行之间的元素并不是严格有序的，所以我们要在每一行都查找一下 mid，
遍历完所有的行可以找出中间数是第几小的数，然后k比较，进行二分查找，left 和 right 最终会相等，并且会变成数组中第k小的数字

使用upper_bound函数，这个函数是查找第一个大于目标数的元素，如果目标数在比该行的尾元素大，
则返回该行元素的个数，如果目标数比该行首元素小，则返回0

举个例子来说吧，比如数组为:
[1 2
12 100]
k = 3
那么刚开始 left = 1, right = 100, mid = 50, 遍历完 cnt = 3，此时 right 更新为 50
此时 left = 1, right = 50, mid = 25, 遍历完之后 cnt = 3, 此时 right 更新为 25
此时 left = 1, right = 25, mid = 13, 遍历完之后 cnt = 3, 此时 right 更新为 13
此时 left = 1, right = 13, mid = 7, 遍历完之后 cnt = 2, 此时 left 更新为8
此时 left = 8, right = 13, mid = 10, 遍历完之后 cnt = 2, 此时 left 更新为 11
此时 left = 11, right = 12, mid = 11, 遍历完之后 cnt = 2, 此时 left 更新为 12
循环结束，left 和 right 均为 12，任意返回一个即可。
整体时间复杂度为 O(nlgn*lgX)，其中X为最大值和最小值的差值
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while(left < right){
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i = 0; i < matrix.size(); ++i)
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if(cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

/* 
进一步优化到 O(nlgX)，其中X为最大值和最小值的差值，
注意到每列也是有序的，从数组的左下角i = m-1, j = 0开始查找，如果比目标值小，j就向右移一列，
和当前位置同列的上面所有的数字都小于目标值，那么 cnt += i+1，反之则向上移一位，这样我们也能算出 cnt 的值。

这里从右上角开始也是一样的，每次查找总能减少一列或者一行
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while(left < right){
            int mid = left + (right - left) / 2;
            int cnt = help(matrix, mid);
            if(cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
    //统计数组中小于target的个数
    int help(vector<vector<int>>& matrix, int target){
        int m = matrix.size();
        int i = m-1, j = 0, res = 0;
        while(i >= 0 && j < m){
            if(matrix[i][j] <= target){
                res += i + 1;
                ++j;
            }
            else
                --i;
        }
        return res;
    }
};



