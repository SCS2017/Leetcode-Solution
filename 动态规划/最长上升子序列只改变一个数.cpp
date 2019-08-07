/* 
牛牛现在有一个n个数组成的数列,牛牛现在想取一个连续的子序列,并且这个子序列还必须得满足:
最多只改变一个数,就可以使得这个连续的子序列是一个严格上升的子序列,牛牛想知道这个连续子序列最长的长度是多少。
*/

/*
分别求以下标i元素为起始点和结束点的递增子序列长度。比较下标i-1和i+1位置的元素差值是否大于2，如果大于2则拼接长度。
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> nums(n);
        vector<int> pre(n,1), last(n,1);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        //pre记录的是以i结尾的递增子序列长度
        for(int i = 1; i < n;i++){    
            pre[i] = nums[i] > nums[i-1] ? pre[i-1]+1 : 1;
        }
        //last记录的是以i开始的递增子序列长度
        for(int i = n-2;i >= 0;i--){  
            last[i] = nums[i+1] > nums[i] ? last[i+1]+1 : 1;
        }
        int res = 1;
        for(int i = 1;i < n-1; i++){
            res = max(res, pre[i]);
            res = max(res, last[i]);
            if(nums[i+1] - nums[i-1] >= 2)
                res=max(res, pre[i-1] + last[i+1] + 1);
        }
        cout << res << endl;
    }
    return 0;
}
