#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include <queue>

using namespace std;

class DenseGraph{
public:
    int n, m;    //n为节点个数，m为边的条数
    bool directed; //是否为有向图
    vector<vector<int> > g;


    DenseGraph(int n, bool directed){
        this->n = n;
        this->m = m;
        this->directed = directed;
        for(int i = 0; i < n; ++i)
            g.push_back(vector<int>(n, 0));
    }
    ~DenseGraph(){

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
        if(hasEdge(v, w))
            return;
        g[v][w] = 1;
        if(!directed)
            g[w][v] = 1;
        ++m;
    }
    bool hasEdge(int v, int w){
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        return (g[v][w] == 1);
    }
    void Print(){
        for(int i = 0; i < g.size(); ++i){
            for(int j = 0; j < g[i].size(); ++j){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }
    void dfs(int v){
        assert(v >= 0 && v < n);
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
                if(b == 1 && !visited[i])
                    s.push(i);
            }
        }
        cout << endl;
    }
    void bfs(int v){
        assert(v >= 0 && v < n);
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
                if(b == 1 && !visited[i])
                    que.push(i);
            }
        }
        cout << endl;
    }

};

int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    DenseGraph myGraph(vertex, false);
    for(int i = 0; i < edge; ++i){
        int from, to;
        cin >> from >> to;
        assert( from >= 0 && from < vertex );
        assert( from >= 0 && from < vertex );
        myGraph.addEgde(from, to);
    }
    myGraph.Print();
    myGraph.dfs(0);
    myGraph.bfs(0);
    return 0;
}
