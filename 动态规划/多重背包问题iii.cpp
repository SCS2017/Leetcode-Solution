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
0 < W ≤ 20000
0 <wi,vi,si ≤ 20000

提示
本题考查多重背包的单调队列优化方法。

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


/* 
首先优化思路来自最最原始的无优化的方程。
仔细观察，对于任意的j，都是从v[i]的倍数转移过来的。它们本来应该是连续的，可以用滑动窗口解决。
但在无优化的时候却每次把所有的倍数都遍历了一遍。所以可以把m根据模v[i]的余数分为v[i]类。

for(int j=0;j<v;j++)
此时对于任意的j，只需要向v[i]的倍数去转移。所以我们在下一层循环的时候把k定义为j+k*v[i]

for(int k=j;k<=m;k+=v)
此时的k相当于原来的j，但是我们可以利用k和v之间存在的倍数关系去做滑动窗口。

由于滑动窗口记录的是下标，但每一个k所对应的下标都是在变化的。
所以要根据当前的k判断窗口里存在的k对应的值包含了多少个v，以便于计算新的价值

v的个数=(下标-余数)/v   价值=(下标-余数)/v*w
       =(q[h]-j)/v          =(k-j)/v*w
然后每次只用了前i-1的值，所以可以滚动数组优化一下空间

*/
int n, m;
int f[20002], q[20002], g[20002];
int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof(f));
        for (int j = 0; j < v; ++j) {
            // hh为队首位置，tt为队尾位置
            // 数值越大，表示位置越后面，队首在队尾后面队列为空，即hh>tt时队列为空
            int hh = 0, tt = -1;
            // q[]为单调队列，存储前个s(物品数量)中的最大值，数组从头(hh)到尾(tt)单调递减
            for (int k = j; k <= m; k += v) {
                // f[k] = g[k]; 
                // 这一行我没理解有什么用，去掉后也能ac？我认为前面使用过了memcpy,这里应该一定是相等的

                // k代表假设当前背包容量为k
                // q[hh]为队首元素（最大值的下标）
                // g[]为dp[i-1][]
                // f[]为dp[i][]

                /*
                维护一个大小为k的区间，使最大值为前k个元素中最大
                (k - q[hh]) / v 表示拿取物品的数量（相当于最原始的多重背包dp的k）
                */
                if (hh <= tt && (k - q[hh]) / v > s) {
                    hh++;
                }

                /*
                若队内有值，该值就是前k个元素的最大值
                (k - q[hh]) / v 表示拿取物品的数量（相当于最原始的多重背包dp的k）
                q[hh]为队首元素（g[]中前k个数中最大值的下标），g[]为dp[i-1][]
                所以 g[q[hh]]为只考虑前i-1个物品时，拿前q[hh]个物品的最大价值
                */
                if (hh <= tt) {
                    f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w);
                }

                /*
                若队尾元素小于当前元素，则队尾元素出队；
                若队内一个元素比当前元素小，则该元素一定不会被用到（单调队列思想）
                g[q[tt]] + (k - q[tt]) / v * w 与g[k] - (k - j) / v * w 分别表示队尾元素的值和当前元素的值
                */
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) {
                    tt--;
                }

                //去除了比当前小的元素，保证队列里的元素都比当前元素大，入队
                q[++tt] = k;
            }
        }
    }
    cout << f[m] << endl;
}
