#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
const int INF = 99999999;
int map[maxn][maxn], dist[maxn];
bool visit[maxn];
int N,P,C;
void init()     //初始化
{
    int i, j;
    for(i = 0; i < maxn; i++)
    {
        for(j = 0; j < maxn; j++)
        {
            if(i == j)
                map[i][j] = 0;
            else
                map[i][j] = map[j][i] = INF;
        }
    }
}
 
void input()    //输入函数
{
    int vi, vj, cost;
    while(P--)
    {
        scanf("%d %d %d", &vi, &vj, &cost);
        if(cost < map[vi][vj])
            map[vi][vj] = map[vj][vi] = cost;
    }
}
 
void floyd()    //Floyd算法
{
    int i, j, k;
    for(k = 0; k <=N; k++)     //k为中间点
        for(i = 0; i <= N; i++)
            for(j = 0; j <= N; j++)
                if(map[i][k] + map[k][j] <  map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
}
int main()
{
  // freopen("in.txt","r",stdin);
    while(cin>>N>>P>>C)
    {
        init();
        input();
        floyd();
        int sum = 0;
        for(int i=0; i<C; ++i)
        {
            int v;cin>>v;
            sum+=map[0][v];
        }
        printf("%d\n", sum);
    }
    return 0;
}