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
0 < N ≤ 1000
0 < W ≤ 2000
0 < wi,vi,si ≤ 2000

提示：
本题考查多重背包的二进制优化方法。

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

// 转成01背包问题，超时
/* 
int main(){
    int N, W;
    cin >> N >> W;
    vector<int> w, v;
    int weight, value, cnt;
    for(int i = 0; i < N; ++i){
        cin >> weight >> value >> cnt;
        for(int j = 0; j < cnt; ++j){
            w.push_back(weight);
            v.push_back(value);
        }
    }
    int length = w.size();
    vector<int> dp(W+1, 0);
    for(int i = 0; i < length; ++i){
        for(int j = W; j >= 0; --j){
            if(j >= w[i])
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}
*/

/* 
上面的方法时间复杂度为O(W*物品数量)，将每种物品分别看成多个单件物品
下面的方法时间复杂度为O(W*log(物品数量))，将数组压缩成log(物品数量)长
*/

int main(){
    int N, W;
    cin >> N >> W;
    vector<int> weight, value;
    vector<int> dp(W+1, 0);
    int w, v, cnt;
    for(int i = 0; i < N; ++i){
        cin >> w >> v >> cnt;
        // 二进制拆分
        // 把N个物品分解 例如s个i物品, 分解为1 + 2 + 4 + 8 ...个i物品 ,然后组合形成一个新物品,存入数组中 
        for(int k = 1; k <= cnt; cnt -= k, k <<= 1){
            weight.push_back(k * w);
            value.push_back(k * v);
        }
        if(cnt){
            weight.push_back(cnt * w);
            value.push_back(cnt * v);
        }
    }
    for(auto w: weight)
        cout << w << " ";
    cout << endl;
    for(auto v: value)
        cout << v << " ";
    cout << endl;
    //01背包
    for(int i = 0; i < weight.size(); ++i){
        for(int j = W; j >= weight[i]; --j)
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
    }
    cout << dp[W] << endl;
    return 0;
}