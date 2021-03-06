/*
给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。 
输入描述:
输入为两行:
第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)
第二行为n个正整数A[i](32位整数)，以空格隔开。

输出描述:
输出所求的方案数

示例1
输入
5 15 
5 5 10 2 3
输出
4
*/

/*
此题使用递归的遍历方法也可以解决，但是会超时
dp解决：
以每个物品作为横轴，以背包容量作为纵轴
    0 1 2 3 4 5 6..........
  0 1 0 0 0 0 0 0..........
  5 1 0 0 0 0 1 0
      
其中1表示前n件物品放入容量为M的背包有1种方法，（5，0）表示重量为5的物品放入容量为0的背包的背包有1中方法，即不放入。
0表示恰好放满背包的方法为0。当M>weight[i]时，dp[M]=dp[M]+dp[M-weight[i]];意义是：放入物品i和不放入物品i的方法总和
*/

//递归会超时，只能过40%，用dp. dp[i][j]表示用前i个值组成和为j的方案个数（相比一维的，更容易理解一些）

#include <iostream>
#include <algorithm>

using namespace std;
//注意：最终结果int类型存不下，需要64位数据
//注意：dp不能放在main里，栈存不下。需要存在全局数据区
long long dp[1001][1001];
int main()
{
    int n,sum;
    cin >> n >> sum;
 
    int p[1000];
    for(int i = 1; i <= n ; i++)
        cin >> p[i];
    //初始化dp,用前i个组成和为0的方案，只有1种，就是什么都不取，和为0
    for (int i = 0; i < n ;i++){
        dp[i][0] = 1;
    }
    //用0个元素不能组成1~sum
    for (int j = 1; j < sum ;j++){
        dp[0][j] = 0;
    }
 
    for (int i = 1; i <= n ;i++){
        for (int j = 0 ; j <= sum ;j++){
            if(j >= p[i]) 
                dp[i][j] = dp[i-1][j] + dp[i-1][j-p[i]];
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][sum] << endl;
    return 0;
}