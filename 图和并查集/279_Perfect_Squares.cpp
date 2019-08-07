/*
给定一个正整数n，寻找最少的完全平方数使它们的和为n

Example 1:
Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

//没有解怎么办？事实上一定有解，任何数都可以写成多个1相加的和，而1是完全平方数
/*
将整个问题转化成一个图论问题
从n到0，每个数字表示一个节点，如果两个数字x到y相差一个完全平方数，则连接一条边，这样就得到了一个无全图
原问题转化为，求这个无权图中从n到0的最短路径
*/

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> myqueue;
        myqueue.push(make_pair(n, 0));
        //为避免重复，设置是否访问
        vector<bool> visited(n + 1, false);
        visited[n] = true;
        while(!myqueue.empty()){
            int num = myqueue.front().first;
            int step = myqueue.front().second;
            myqueue.pop();
            if(num == 0)
                return step;
            for(int i = 1; num - i * i >= 0; ++i){
                if(!visited[num - i * i]){
                    myqueue.push(make_pair(num - i * i, step + 1));
                    visited[num - i * i] = true;
                }
            }
        }
        throw invalid_argument("no answer!");
    }
};

//修改版，优化性能
class Solution1 {
public:
    int numSquares(int n) {
        queue<pair<int, int>> myqueue;
        myqueue.push(make_pair(n, 0));
        //为避免重复，设置是否访问
        vector<bool> visited(n + 1, false);
        visited[n] = true;
        while(!myqueue.empty()){
            int num = myqueue.front().first;
            int step = myqueue.front().second;
            myqueue.pop();
            for(int i = 1; ; ++i){
                int a = num - i * i;
                if(a < 0)
                    break;
                if(a == 0)
                    return step + 1;
                if(!visited[a]){
                    myqueue.push(make_pair(a, step + 1));
                    visited[a] = true;
                }
            }
        }
        throw invalid_argument("no answer!");
    }
};

/* 
们建立一个长度为n+1的一维dp数组，将第一个值初始化为0，其余值都初始化为INT_MAX, i从0循环到n，j从1循环到 i+j*j <= n 的位置，
然后每次更新 dp[i+j*j] 的值，动态更新 dp 数组，其中 dp[i] 表示正整数i能少能由多个完全平方数组成，那么我们求n，
就是返回 dp[n] 即可，也就是 dp 数组的最后一个数字。
需要注意的是这里的写法，i必须从0开始，j必须从1开始，因为我们的初衷是想用 dp[i] 来更新 dp[i + j * j]，
如果 i=0, j=1 了，那么 dp[i] 和 dp[i + j * j] 就相等了，怎么能用本身 dp 值加1来更新自身呢
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};

/*
根据四平方和定理，任意一个正整数均可表示为4个整数的平方和，其实是可以表示为4个以内的平方数之和，
那么就是说返回结果只有1,2,3或4其中的一个，首先我们将数字化简一下，由于一个数如果含有因子4，那么我们可以把4都去掉，
并不影响结果，比如2和8,3和12等等，返回的结果都相同，读者可自行举更多的栗子。
还有一个可以化简的地方就是，如果一个数除以8余7的话，那么肯定是由4个完全平方数组成，这里就不证明了，
因为我也不会证明，读者可自行举例验证。那么做完两步后，一个很大的数有可能就会变得很小了，大大减少了运算时间，
下面我们就来尝试的将其拆为两个平方数之和，如果拆成功了那么就会返回1或2，因为其中一个平方数可能为0. 
(注：由于输入的n是正整数，所以不存在两个平方数均为0的情况)。注意下面的 !!a + !!b 这个表达式，
可能很多人不太理解这个的意思，其实很简单，感叹号!表示逻辑取反，那么一个正整数逻辑取反为0，再取反为1，
所以用两个感叹号!!的作用就是看a和b是否为正整数，都为正整数的话返回2，只有一个是正整数的话返回1。
*/
class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0)
            n /= 4;
        if(n % 8 == 7)
            return 4;
        for(int a = 0; a * a <= n; ++a){
            int b = sqrt(n - a * a);
            if(a*a + b*b == n)
                return !!a + !!b;
        }
        return 3;
    }
};

int main()
{
    return 0;
}