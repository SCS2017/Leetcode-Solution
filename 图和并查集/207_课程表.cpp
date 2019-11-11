/*
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:
输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

示例 2:
输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。

说明:
输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
*/

/*
拓扑排序，把一个有向无环图转换成一维的拓扑排序。拓扑排序是对有向无环图的一种排序。表示了顶点按边的方向出现的先后顺序。
如果有环，则无法表示两个顶点的先后顺序。
一个简单的求拓扑排序的算法：首先要找到任意入度为0的一个顶点，删除它及所有相邻的边，
再找入度为0的顶点，以此类推，直到删除所有顶点。顶点的删除顺序即为拓扑排序。这里要用到BFS。
*/

/*
解答
考察拓扑排序，利用课程之间的关系建立有向图，如果课程A之前需要完成课程B，那么在图中A指向B，同时定义数组degree统计每个节点的入度。
定义队列que，首先将当前入度为0的节点(优先需要学习的课程)加入队列，定义变量cnt用于计数。
然后进入循环，每次循环访问队首元素a，并弹出a，访问a指向的每个节点b，将b的入度减1，如果此时b的入度为0，
则此时课程b可以进行学习，将b加入队列，然后进入下一次循环，每次循环都将cnt加1，直到队列为空时结束循环。
最后，如果cnt等于课程数，说明所有的课程都加入过队列，它们可以有序地进行学习，返回true；否则，返回false。

设有向图的顶点数为v，边数为e
时间复杂度：O(v + e)
空间复杂度：O(v + e)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites){
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<int> degree(numCourses);
        for(auto m: prerequisites){
            int from = m[1];
            int to = m[0];
            //from:to 表示to依赖于from
            graph[from].push_back(to);
            //入度
            ++degree[to];
        }
        queue<int> que;
        for(int i = 0; i < degree.size(); ++i){
            if(degree[i] == 0)
                que.push(i);
        }
        int cnt = 0;
        while(!que.empty()){
            int tmp = que.front();
            que.pop();
            cout << tmp << " ";
            for(auto b: graph[tmp]){
                --degree[b];
                if(degree[b] == 0)
                    que.push(b);
            }
            ++cnt;
        }
        if(cnt == numCourses) 
            return true;
        return false;
    }
};

int main(){
    vector<vector<int> > prerequisites = {{3, 0}, {1, 0}, {3, 1}, {2, 1}, {2, 3}, {4, 2}, {4, 3}};
    //  {0, 1, 3, 2, 4}
    bool res = Solution().canFinish(5, prerequisites);
    cout << boolalpha << res << endl;
    return 0;
}
