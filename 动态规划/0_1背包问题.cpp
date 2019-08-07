/*
有一个背包，其容量为C。现在有n种不同的物品，编号为0...n-1，其中每一件物品的重量为w(i)，价值为v(i)。问可以向这个背包
盛放哪些物品，使得在不超过背包容量的基础上，物品的总价值最大。
*/
#include <iostream>
#include <vector>

using namespace std;

/*状态转移方程，比较将物品放入背包和不放入背包的价值
F(i, c) = max(F(i - 1, c), v(i) + F(i - 1, c - w(i)))
*/
//记忆搜索解法
class Solution{
public:
    //w为物品的重量，v为物品的价值，C为背包的重量
    int knapsack01(const vector<int>& w, const vector<int>& v, int C){
        int n = w.size();
        memo = vector<vector<int> >(n, vector<int>(C + 1, -1));
        return bestValue(w, v, n - 1, C);
    }
private:
    vector<vector<int> > memo;
    //用[0...index]的物品，填冲容积为c的背包的最大价值
    int bestValue(const vector<int>& w, const vector<int>& v, int index, int c){
        if(index < 0 || c <= 0){
            return 0;
        }
        if(memo[index][c] != -1){
            return memo[index][c];
        }
        int res = bestValue(w, v, index - 1, c);
        if(w[index] <= c){
            res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
        }
        memo[index][c] = res;
        return res;
    }
};

//动态规划解法
//时间复杂度和空间复杂度均为O(n*C)
class Solution1{
public:
    //w为物品的重量，v为物品的价值，C为背包的重量
    int knapsack01(const vector<int>& w, const vector<int>& v, int C){
        int n = w.size();
        if( n == 0){
            return 0;
        }
        //行为考虑这个物品，列为背包重量的限制
        vector<vector<int> > memo(n, vector<int>(C + 1, -1));
        for(int j = 0; j <= C; ++j){
            memo[0][j] = (j >= w[0] ? v[0] : 0);
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= C; ++j){
                memo[i][j] = memo[i - 1][j];
                if(w[i] <= j){
                    memo[i][j] = max(memo[i][j], v[i] + memo[i -1][j - w[i]]);
                }
            }
        }
        return memo[n - 1][C];
    }
};

//优化空间复杂度
//F(i, c) = max(F(i - 1, c), v(i) + F(i - 1, c - w(i)))
//理论上，只需要保持两行元素，空间复杂度为O(2*C) = O(C)
//  i = 0  i = 2  i = 2  i = 4 
//  i = 1  i = 1  i = 3  i = 3

class Solution2{
public:
    //w为物品的重量，v为物品的价值，C为背包的重量
    int knapsack01(const vector<int>& w, const vector<int>& v, int C){
        int n = w.size();
        if( n == 0){
            return 0;
        }
        vector<vector<int> > memo(2, vector<int>(C + 1, -1));
        for(int j = 0; j <= C; ++j){
            memo[0][j] = (j >= w[0] ? v[0] : 0);
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= C; ++j){
                memo[i % 2][j] = memo[(i - 1) % 2][j];
                if(w[i] <= j){
                    memo[i % 2][j] = max(memo[i % 2][j], v[i] + memo[(i - 1) % 2][j - w[i]]);
                }
            }
        }
        return memo[(n - 1) % 2][C];
        
    }
};

//只用一行元素
class Solution3{
public:
    //w为物品的重量，v为物品的价值，C为背包的重量
    int knapsack01(const vector<int>& w, const vector<int>& v, int C){
        int n = w.size();
        if( n == 0){
            return 0;
        }
        vector<int> memo(C + 1, -1);
        for(int j = 0; j <= C; ++j){
            memo[j] = (j >= w[0] ? v[0] : 0);
        }
        for(int i = 1; i < n; ++i){
            for(int j = C; j >= w[i]; --j){
                memo[j] = max(memo[j], v[i] + memo[j - w[i]]);
            }
        }
        return memo[C];
    }
};

int main()
{
    int weight[] = {1, 2, 3};
    int value[] = {6, 10, 12};
    int C = 5;
    int len = sizeof(weight) / sizeof(int);
    vector<int> w(weight, weight + len);
    vector<int> v(value, value + len);
    int res = Solution3().knapsack01(w, v, C);
    cout << res << endl;
    return 0;
}