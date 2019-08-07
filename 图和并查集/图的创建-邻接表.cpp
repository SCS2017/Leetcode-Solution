#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class SparseGraph{
public:
    int n, m;    //n为节点个数，m为边的条数
    bool directed; //是否为有向图
    vector<vector<int> > g;

    SparseGraph(int n, bool directed){
        this->n = n;
        this->m = m;
        this->directed = directed;
        for(int i = 0; i < n; ++i)
            g.push_back(vector<int>());
    }
    ~SparseGraph(){

    }
    int V(){
        return n;
    }
    int E(){
        return m;
    }
    void addEgde(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        g[v].push_back(w);
        if(!directed)
            g[w].push_back(v);
        ++m;
    }
    bool hasEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        for(int i = 0; i < g[v].size(); ++i){
            if(g[v][i] == w)
                return true;
        }
        return false;
    }
    void Print(){
        
        for(int i = 0; i < g.size(); ++i){
            cout << "边" << i << ":";
            for(int j = 0; j < g[i].size(); ++j){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int v){
        
        vector<bool> visited(n, false);
        stack<int> s;
        s.push(v);
        while(!s.empty()){
            int tmp = s.top();
            //这里如果不加条件，遍历结果会出现重复值
            if(!visited[tmp])
                cout << tmp << " ";
            visited[tmp] = true;
            s.pop();
            int size = g[tmp].size();
            for(int i = 0; i < size; ++i){
                int b = g[tmp][i];
                if(!visited[b])
                    s.push(b);
            }
        }
        cout << endl;
    }
    void bfs(int v){
        
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(v);
        while(!que.empty()){
            int tmp = que.front();
            if(!visited[tmp])
                cout << tmp << " ";
            visited[tmp] = true;
            que.pop();
            int size = g[tmp].size();
            for(int i = 0; i < size; ++i){
                int b = g[tmp][i];
                if(!visited[b])
                    que.push(b);
            }
        }
        cout << endl;
    }
};

int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    SparseGraph myGraph(vertex, false);
    for(int i = 0; i < edge; ++i){
        int from, to;
        cin >> from >> to;
        assert( from >= 0 && from < vertex );
        assert( from >= 0 && from < vertex );
        myGraph.addEgde(from, to);
    }
    cout << "图的邻接表实现: "  << endl;
    myGraph.Print();
    cout << "深度优先遍历结果: " << endl;
    myGraph.dfs(0);
    cout << "广度优先遍历结果: " << endl;
    myGraph.bfs(0);
    return 0;
}
