/* 
在本问题中, 树指的是一个连通且无环的无向图。
输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。
附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，表示连接顶点u 和v的无向图的边。
返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，则返回二维数组中最后出现的边。
答案边 [u, v] 应满足相同的格式 u < v。

示例 1：
输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的无向图为:
  1
 / \
2 - 3

示例 2：
输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
解释: 给定的无向图为:
5 - 1 - 2
    |   |
    4 - 3

注意:
输入的二维数组大小在 3 到 1000。
二维数组中的整数在1到N之间，其中N是输入数组的大小。
*/

#include <bits/stdc++.h>
using namespace std;

/* 
递归
每加入一条边，就进行环的检测，一旦发现环，就返回当前边。对于无向图，使用邻接表存储，建立每个节点到其所有邻接点的映射，
由于两个结点不算有环，我们要避免1->{2}，2->{1}的死循环，所以我们使用一个变量pre来记录上一次递归的结点，
比如上一次遍历的节点是1，那么在遍历结点2的邻接表时，就不会在进入结点1了。
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> g;
        for(auto edge: edges){
            if(hasCycle(edge[0], edge[1], g, -1))
                return edge;
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        } 
        return {};
    }
    bool hasCycle(int u, int v, unordered_map<int, unordered_set<int>>& g, int pre){
        if(g[u].count(v))
            return true;
        for(int num: g[u]){
            if(num == pre)
                continue;
            if(hasCycle(num, v, g, u))
                return true;
        }
        return false;
    }
};

/*并查集 
若root[1] = 2，就表示结点1和结点2是相连的，root[2] = 3表示结点2和结点3是相连的，如果我们此时新加一条边[1, 3]的话，
我们通过root[1]得到2，再通过root[2]得到3，说明结点1有另一条路径能到结点3，这样就说明环是存在的；
如果没有这条路径，那么我们要将结点1和结点3关联起来，让root[1] = 3即可
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(2001, -1);
        for(auto edge: edges){
            int x = find(parent, edge[0]), y = find(parent, edge[1]);
            if(x == y)
                return edge;
            parent[x] = y;
        }
        return {};
    }
    int find(vector<int>& parent, int u){
        while(parent[u] != -1)
            u = parent[u];
        return u;
    }
};

int main(){
    
    return 0;
}
