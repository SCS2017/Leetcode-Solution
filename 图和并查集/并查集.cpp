#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class UnionFind{
private:
    vector<int> parent;
    int count;
    vector<int> rank;  //优化，记录p和q所在组的深度，在合并时将深度小的结点的根指向深度大的结点的根

public:
    UnionFind(int count){
        parent.resize(count);
        rank.resize(count);
        this->count = count;
        for(int i = 0; i < count; ++i){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    ~UnionFind(){
        parent.clear();
        rank.clear();
    }
    int find(int p){
        assert(p >= 0 && p < count);
        while(p != parent[p])
            p = parent[p];
        return p;
    }
    //路径压缩
    int find(int p){
        assert(p >= 0 && p < count);
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }
    bool isConnected(int p, int q){
        return find(p) == find(q);
    }
    void unionElement(int p, int q){
        int pRoot = find(p), qRoot = find(q);
        if(pRoot == qRoot)
            return;
        parent[pRoot] = qRoot;
    }

    void unionElement1(int p, int q){
        int pRoot = find(p), qRoot = find(q);
        if(pRoot == qRoot)
            return;
        if(rank[pRoot] < rank[qRoot])
            parent[pRoot] = qRoot;
        else if(rank[qRoot] < rank[pRoot])
            parent[qRoot] = pRoot;
        else{
            //两者的rank相等
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};

int main(){
    
    return 0;
}
