/*
在一次聚会中，你想找出来聚会的人中所有的名人，名人就是别人认识他，而他不认识别人。现在在聚会的k个人中，
输入邻接矩阵adj[i][j]用来表示他们之间的关系，其中 adj[i][j]=1表示i认识j,adj[i][j]=0表示i不认识j。

输入:第一行输入k，表示一共有k个人,编号从1到k
之后k行输入邻接矩阵

输出:输出所有名人的编号，没有名人则输出-1

输入示例:                                                     
3                                                                  
0 1 0
0 0 0
1 1 1

输出示例:
2
*/

#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000;
int adj[MAX][MAX];

int findFamous(int n){
    int i = 0, j = n - 1;    
    //i,j的意义:
    //i,j表示有可能是名人的两个人,且下标为0~i-1的人不是名人;下标j+1~n-1的不是名人
    while(i < j){
        //i认识j,说明i不是名人，那么这时 i++,则i左侧不是名人的范围扩大
        if(adj[i][j])
            ++i;
        //在i认识j时，直接j--,就行，j+1~n-1范围扩大一个
        else
            --j;    
    }
    //最终i=j,由逻辑上可以知道，最对只有一个名人，下标为i,则最终i左边0~i-1和i右边i+1~n-1都不是名人 
    for(int k = 0; k < n; ++k){
        if(k != i && (adj[i][k] == 1 || adj[k][i] == 0))
            return -1;
    }
    return i+1;
}

bool knows(int a, int b);
/* 
对于不是名人的i，直接 break，继续检查下一个，但是由于我们没有标记后面的候选人的状态，所以有可能会重复调用一些 knows 函数，
所以下面这种方法虽然省了空间，但是调用 knows 函数的次数可能会比上面的方法次数要多
*/
class Solution {
public:
    int findCelebrity(int n) {
        for (int i = 0, j = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i != j && (knows(i, j) || !knows(j, i))) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
/* 
下面这种方法是网上比较流行的一种方法，设定候选人 res 为0，原理是先遍历一遍，对于遍历到的人i，若候选人 res 认识i，
则将候选人 res 设为i，完成一遍遍历后，我们来检测候选人 res 是否真正是名人，我们如果判断不是名人，则返回 -1，如果并没有冲突，返回 res，
*/
class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (knows(res, i)) res = i;
        }
        for (int i = 0; i < n; ++i) {
            if (res != i && (knows(res, i) || !knows(i, res))) return -1;
        }
        return res;
    }
};


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> adj[i][j];
        }
    }
    int res = findFamous(n);
    cout << res << endl;
    return 0;
}
