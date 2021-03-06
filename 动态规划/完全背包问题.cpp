/* 
有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。
第 i 种物品的体积是 wi，价值是 vi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行两个整数 wi，vi，用空格隔开，分别表示第 i 种物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0 < N,V ≤1000
0 < wi,vi ≤1000

输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
10
*/

//每种物品都有无限件可用
/* 
几乎与01背包的一维解答一模一样，唯一的区别是w的遍历次序是递增的。
那么就是说明dp转移方程dp[j] = max(dp[j] , dp[j-w[i]]+v[i]);
dp依赖的状态未必是i-1轮的状态 而是同一轮中较小的j。 这也符合题意。
01背包中要验证当前第i个物品是否拿还是不拿必须依赖上一轮(i-1)轮的状态，这个状态是绝对不会出现已经拿取了第i个物品的情况。
但是在完全背包中，由于物品有多个，可能要验证当前是否拿第i个物品所依赖的状态已经取过若干个第i个物品了
所以w的遍历是由小到大递增的。
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int w[maxn], v[maxn], dp[maxn];

int main(){
    int N, W;
    cin >> N >> W;
    for(int i = 1; i <= N; ++i)
        cin >> w[i] >> v[i];
    for(int i = 1; i <= N; ++i){
        for(int j = w[i]; j <= W; ++j)
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    }
    cout << dp[W] << endl;
    return 0;
}
