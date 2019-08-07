/* 
有 N 种物品和一个容量是 W 的背包。
第 i 种物品最多有 si 件，每件体积是 wi，价值是 vi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，W，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 wi,vi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0 < N,V ≤100
0 < wi,vi,si ≤100

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int w[maxn], v[maxn], c[maxn], dp[maxn];

int main(){
    int N, W;
    cin >> N >> W;
    for(int i = 1; i <= N; ++i)
        cin >> w[i] >> v[i] >> c[i];
    for(int i = 1; i <= N; ++i){
        for(int j = W; j >= 0; --j){
            for(int k = 1; k <= c[i]; ++k){
                if(j >= w[i] * k)
                    dp[j] = max(dp[j], dp[j-w[i]*k] + v[i]*k);
            }
        }
    }
    cout << dp[W] << endl;
    return 0;
}
