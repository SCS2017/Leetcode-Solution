/*
给出方程式 A / B = k, 其中 A 和 B 均为代表字符串的变量， k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回 -1.0。

示例 :
给定 a / b = 2.0, b / c = 3.0
问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
返回 [6.0, 0.5, -1.0, 1.0, -1.0 ]

输入为: 
vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries
(方程式，方程式结果，问题方程式)， 
其中 equations.size() == values.size()，即方程式的长度与方程式结果长度相等（程式与结果一一对应），并且结果值均为正数。
以上为方程式的描述。 返回vector<double>类型。

基于上述例子，输入如下：

equations(方程式) = [ ["a", "b"], ["b", "c"] ],
values(方程式结果) = [2.0, 3.0],
queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。
*/

/*分析
四个已知条件：
1) 已知: a / b = 2，b / a = 1/2，b / c = 3，c / b = 1/3，求 a / c
2) 已知: a / c = 2，c / a = 1/2，b / c = 3，c / b = 1/3，求 a / b
3) 已知: a / b = 2，b / a = 1/2，a / c = 3，c / a = 1/3，求 b / c
*/

#include <bits/stdc++.h>

using namespace std;

//HashSet来记录已经访问过的表达式，然后对其调用递归函数
class Solution {
public:
    vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
        for(int i = 0; i < equations.size(); ++i){
            m[equations[i][0]][equations[i][1]] = values[i];
            m[equations[i][1]][equations[i][0]] = 1 / values[i];    
        }
        vector<double> res;
        for(auto query: queries){
            unordered_set<string> visited;
            double t = help(query[0], query[1], visited);
            res.push_back((t > 0.0) ? t : -1);
        }
        return res;
    }
    double help(string a, string b, unordered_set<string>& visited){
        if(m[a].find(b) != m[a].end())
            return m[a][b];
        for(auto up: m[a]){
            if(visited.find(up.first) != visited.end())
                continue;
            visited.insert(up.first);
            double t = help(up.first, b, visited);
            if(t > 0.0)
                return t * up.second;
        }
        return -1.0;
    }
private:
    unordered_map<string, unordered_map<string, double> > m;
};

/*
emplace_front、emplace和emplace_back，这些操作构造而不是拷贝元素。这些操作分别对应push_front、insert和push_back，
允许我们将元素放置在容器头部、一个指定位置之前或容器尾部。
*/
//邻接列表的表示方法建立了一个图，然后进行bfs搜索，需要用queue来辅助运算
class Solution1 {
public:
    vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
        unordered_map<string, unordered_map<string, double> > m;
        vector<double> res;
        for(int i = 0; i < equations.size(); ++i){
            m[equations[i][0]].emplace(equations[i][1], values[i]);
            m[equations[i][1]].emplace(equations[i][0], 1 / values[i]);
            // m[equations[i][0]].emplace(equations[i][0], 1.0);
            // m[equations[i][1]].emplace(equations[i][1], 1.0);
        }
        for(auto query: queries){
            if(!m.count(query[0]) || !m.count(query[1])){
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string, double> > q;
            unordered_set<string> visited{query[0]};
            bool found = false;
            q.push({query[0], 1.0});
            while(!q.empty() && !found){
                auto t = q.front();
                q.pop();
                //如果查询为['a', 'a']
                if(t.first == query[1]){
                    found = true;
                    res.push_back(t.second);
                    break;
                }
                for(auto a: m[t.first]){
                    if(visited.find(a.first) != visited.end())
                        continue;
                    visited.insert(a.first);
                    a.second *= t.second;
                    q.push(a);
                }
            }
            if(!found)
                res.push_back(-1.0);
        }
        return res;
    }
};


//并查集
class Solution2 {
public:
    vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries) {
        unordered_map<string, Node* > m;
        vector<double> res;
        for(int i = 0; i < equations.size(); ++i){
            string s1 = equations[i][0], s2 = equations[i][1];
            if(m.count(s1) == 0 && m.count(s2) == 0){
                m[s1] = new Node();
                m[s2] = new Node();
                m[s1]->value = values[i];
                m[s2]->value = 1;
                m[s1]->parent = m[s2];
            }
            else if(m.count(s1) == 0){
                m[s1] = new Node();
                m[s1]->value = m[s2]->value * values[i];
                m[s1]->parent = m[s2];
            }
            else if(m.count(s2) == 0){
                m[s2] = new Node();
                m[s2]->value = m[s1]->value / values[i];
                m[s2]->parent = m[s1];
            }
            else{
                unionNodes(m[s1], m[s2], values[i], m);
            }
        }
        for(auto query: queries){
            if(m.count(query[0]) == 0 || m.count(query[1]) == 0 || findParent(m[query[0]]) != findParent(m[query[1]])){
                res.push_back(-1);
            }
            else{
                res.push_back(m[query[0]]->value / m[query[1]]->value);
            }
        }
        return res;
    }

private:
    struct Node{
        Node* parent;
        double value = 0.0;
        Node(){parent = this;}
    };
    Node* findParent(Node* node){
        if(node != node->parent)
            node->parent = findParent(node->parent);
        return node->parent;
    }
    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map){
        Node* parent1 = findParent(node1), *parent2 = findParent(node2);
        double ratio = node2->value * num / node1->value;
        for(auto it = map.begin(); it != map.end(); ++it){
            if(findParent(it->second) == parent1)
                it->second->value *= ratio;
        }
        parent1->parent = parent2;
    }
};

int main(){

    return 0;
}
